#pragma once
#include "google/protobuf/service.h"
#include <memory>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <unordered_map>

// 框架提供的专门服务发布rpc服务的网络对象类
class RpcProvider {
public:
    // 接收service基类
    void NotifyService(::google::protobuf::Service* service);

    // 启动rpc服务节点，开始提供rpc远程调用服务
    void Run();

private:
    // 组合了Tcpserver
    // std::unique_ptr<muduo::net::TcpServer> m_tcpServerPtr;
    // 组合了EventLoop
    muduo::net::EventLoop m_eventLoop;
    
    // 设置新的socket连接回调
    void OnConnection(const muduo::net::TcpConnectionPtr&);

    void OnMessage(const muduo::net::TcpConnectionPtr&,
        muduo::net::Buffer*,
        muduo::Timestamp);
    
    // 服务类型信息 方法表
    struct ServiceInfo {
        google::protobuf::Service* m_service;
        // 保存服务方法
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor*> m_methodMap;
    };

    // 存储注册成功的服务对象和其服务方法的所有信息
    std::unordered_map<std::string, ServiceInfo> m_serviceMap;

    // Closure回调函数
    void sendRpcResponse(const muduo::net::TcpConnectionPtr&, google::protobuf::Message*);
    
};