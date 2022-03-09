#include "MpRpcChannel.h"
#include "RpcHeader.pb.h"
#include "MpRpcApplication.h"
#include "MpRpcController.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
#include <errno.h>
#include <unistd.h>

void MpRpcChannel::CallMethod(const google::protobuf::MethodDescriptor* method,
    google::protobuf::RpcController* controller,
    const google::protobuf::Message* request,
    google::protobuf::Message* response,
    google::protobuf::Closure* done) {

    const google::protobuf::ServiceDescriptor* service_des = method->service();
    std::string service_name = service_des->name();
    std::string method_name = method->name();

    // 获取参数的序列化字符串长度 args_size
    int args_szie = 0;
    std::string args_str;
    if (request->SerializeToString(&args_str)) {
        args_szie = args_str.size();
    }
    else {
        controller->SetFailed("serialize request failed !");
        return;
    }

    // 定义mrpc的请求header
    MpRpc::RpcHeader rpc_header;
    rpc_header.set_args_size(args_szie);
    rpc_header.set_method_name(method_name);
    rpc_header.set_service_name(service_name);

    std::string rpc_header_str;
    int header_size = 0;
    if (rpc_header.SerializeToString(&rpc_header_str)) {
        header_size = rpc_header_str.size();
    }
    else {
        controller->SetFailed("serialize rpc header failed !");
        return;
    }
    std::string send_rpc_str;
    send_rpc_str.insert(0, std::string((char*)&header_size, 4));
    send_rpc_str += rpc_header_str;
    send_rpc_str += args_str;


    // 使用tcp编程 
    std::string ip = MpRpcApplication::GetInstance().GetConfig().Load("rpcserverip");
    uint16_t port = atoi(MpRpcApplication::GetInstance().GetConfig().Load("rpcserverport").c_str());

    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == client_fd) {
        controller->SetFailed("create socket errno : ");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    if (-1 == connect(client_fd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr))) {
        char errtxt[512] = { 0 };
        sprintf(errtxt, "connect errno : %d", errno);
        controller->SetFailed(errtxt);
        close(client_fd);
        return;
    }
    if (-1 == send(client_fd, send_rpc_str.c_str(), send_rpc_str.size(), 0)) {
        char errtxt[512] = { 0 };
        sprintf(errtxt, "send errno : %d", errno);
        controller->SetFailed(errtxt);
        close(client_fd);
        return;
    }
    // 接收rpc请求的响应值
    char recv_buf[1024] = { 0 };
    int recv_size = 0;
    if (-1 == (recv_size = recv(client_fd, recv_buf, 1024, 0))) {
        char errtxt[512] = { 0 };
        sprintf(errtxt, "recv errno : %d", errno);
        controller->SetFailed(errtxt);
        close(client_fd);
        return;
    }
    // 反序列化rpc response
    // std::string response_str(recv_buf, 0, recv_size);
    if (!response->ParseFromArray(recv_buf, recv_size)) {
        char errtxt[1100] = { 0 };
        sprintf(errtxt, "parse response error : %s ", recv_buf);
        controller->SetFailed(errtxt);
        close(client_fd);
        return;
    }
    close(client_fd);
}

