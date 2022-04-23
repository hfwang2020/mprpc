#include "RpcProvider.h"
#include <string>
#include "MpRpcApplication.h"
#include <functional>
#include "google/protobuf/descriptor.h"
#include "RpcHeader.pb.h"
#include "ZookeeperUtil.h"

// 发布服务 传入服务子类 把注册的服务存入对象内的map
void RpcProvider::NotifyService(google::protobuf::Service* service) {
    
    ServiceInfo service_info;
    service_info.m_service = service;

    // 获取对象的服务描述符
    const google::protobuf::ServiceDescriptor* pserviceDesc = service->GetDescriptor();
    // 获取服务的名字
    std::string service_name = pserviceDesc->name();

    std::cout << "notify service: " << service_name << std::endl;
    
    // 获取服务对象service方法的数量
    int methodCnt = pserviceDesc->method_count();
    
    for (int i = 0; i < methodCnt; i++) {
        // 获取服务对象指定下标的服务方法的描述
        const google::protobuf::MethodDescriptor* pmethodDesc = pserviceDesc->method(i);
        std::string method_name = pmethodDesc->name();
        std::cout << "   the " << i << "th method name: " << method_name << std::endl;
        service_info.m_methodMap.insert({ method_name,pmethodDesc });
    }

    m_serviceMap.insert({ service_name, service_info });
}

void RpcProvider::Run() {
    // std
    std::string ip = MpRpcApplication::GetInstance().GetConfig().Load("rpcserverip");
    uint16_t port = atoi(MpRpcApplication::GetInstance().GetConfig().Load("rpcserverport").c_str());
    muduo::net::InetAddress address(ip, port);

    std::cout << "RpcProvider start service at " << ip << ":" << port << std::endl;

    // 创建TcpServer对象
    muduo::net::TcpServer server(&m_eventLoop, address, "RpcProvider");
    // 绑定连接回调和消息读写回调方法 分离网络代码和业务代码
    server.setConnectionCallback(std::bind(&RpcProvider::OnConnection,
        this,
        std::placeholders::_1));

    server.setMessageCallback(std::bind(&RpcProvider::OnMessage,
        this,
        std::placeholders::_1,
        std::placeholders::_2,
        std::placeholders::_3));

    // 设置muduo库的线程数量
    server.setThreadNum(4);

    // 服务注册到zk上
    ZkClient zk_cli;
    zk_cli.start();
    for (auto& sp : m_serviceMap) {
        std::string service_path = "/" + sp.first;
        zk_cli.create(service_path.c_str(), nullptr, 0);
        for (auto& mp : sp.second.m_methodMap) {
            std::string method_path = service_path + "/" + mp.first;
            char method_path_data[128] = { 0 };
            sprintf(method_path_data, "%s:%d", ip.c_str(), port);
            zk_cli.create(method_path.c_str(), method_path_data, strlen(method_path_data), ZOO_EPHEMERAL);
        }
    }
    server.start();

    m_eventLoop.loop();

};

// 设置新的socket连接回调
void  RpcProvider::OnConnection(const muduo::net::TcpConnectionPtr& conn) {
    if (!conn->connected()) {
        conn->shutdown();   // 断开连接
    }

};

/*
    在框架内部，RpcProvider和RpcConsumer的数据类型
    service_name method_name args 字符串长度 防止粘包
    定义proto的message类型，进行数据的序列化和反序列化

*/

// 建立连接用户的读写事件回调，响应远程有一个rpc服务调用请求
void RpcProvider::OnMessage(const muduo::net::TcpConnectionPtr& conn,
    muduo::net::Buffer* buffer,
    muduo::Timestamp) {

    // 接收的远程rpc调用的请求字符流
    std::string recv_buf = buffer->retrieveAllAsString();
    // 从字符流读取前四个字节
    uint32_t header_size = 0;
    recv_buf.copy((char*)(&header_size), 4, 0);

    // 根据header_size读取数据头原始字符流 反序列化
    std::string rpc_header_str = recv_buf.substr(4, header_size);
    MpRpc::RpcHeader rpc_header;

    std::string service_name;
    std::string method_name;
    uint32_t args_size;

    if (rpc_header.ParseFromString(rpc_header_str)) {
        // 数据头反序列化
        service_name = rpc_header.service_name();
        method_name = rpc_header.method_name();
        args_size = rpc_header.args_size();
    }
    else {
        std::cout << "parse header error" << std::endl;
        return;
    }

    std::string args_str = recv_buf.substr(4 + header_size, args_size);


    std::cout << "=================== log ====================" << std::endl;
    std::cout << "head size: " << header_size << std::endl;
    std::cout << "rpc_header_str: " << rpc_header_str << std::endl;
    std::cout << "service name: " << service_name << std::endl;
    std::cout << "method_name: " << method_name << std::endl;
    std::cout << "args_size: " << args_size << std::endl;
    std::cout << "args_str: " << args_str << std::endl;


    // 获取service对象
    auto service_iter = m_serviceMap.find(service_name);
    if (service_iter == m_serviceMap.end()) {
        std::cout << "service name is not exist!" << std::endl;
        return;
    }
    google::protobuf::Service* service = service_iter->second.m_service;
    // 获取method对象
    auto method_map_iter = service_iter->second.m_methodMap.find(method_name);
    if (method_map_iter == service_iter->second.m_methodMap.end()) {
        std::cout << "method(" << method_name << ") is not exist" << std::endl;
        return;
    }
    const google::protobuf::MethodDescriptor* method_des = method_map_iter->second;

    // 生成rpc方法调用的请求requests和response参数
    google::protobuf::Message* request = service->GetRequestPrototype(method_des).New();
    if (!request->ParseFromString(args_str)) {
        std::cout << "parse error!" << std::endl;
        return;
    }

    google::protobuf::Message* response = service->GetResponsePrototype(method_des).New();

    // 绑定回调函数
    // google::protobuf::Closure *done
    google::protobuf::Closure* done =
        google::protobuf::NewCallback<RpcProvider,
        const muduo::net::TcpConnectionPtr&,
        google::protobuf::Message*>
        (this,
            &RpcProvider::sendRpcResponse,
            conn,
            response);
    
    service->CallMethod(method_des, nullptr, request, response, done);
};


void RpcProvider::sendRpcResponse(const muduo::net::TcpConnectionPtr& conn,
    google::protobuf::Message* response) {

    std::string response_str;
    if (response->SerializeToString(&response_str)) {
        // 序列化成功
        conn->send(response_str);
    }
    else {
        std::cout << "serialize response error!";
    }
    conn->shutdown(); // 模拟http的短连接 rpcprovider主动断开服务
}


