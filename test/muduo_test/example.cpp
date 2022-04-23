#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>

#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;


class ChatServer {
public:
    ChatServer(::muduo::net::EventLoop* loop,
        const ::muduo::net::InetAddress& listenAddr,
        const string& nameArg)
        :_server(loop, listenAddr, nameArg)
        , _loop(loop)
    {
        // 给服务器注册用户连接的创建和断开回调
        _server.setConnectionCallback(std::bind(&ChatServer::onConnection, this, _1));
        // 给服务器注册用户读写事件回调
        _server.setMessageCallback(std::bind(&ChatServer::onMessage, this, _1, _2, _3));

        _server.setThreadNum(4);
    }

    void start() {
        _server.start();
    }


private:
    ::muduo::net::TcpServer _server;
    ::muduo::net::EventLoop* _loop;


    // 专门处理用户的连接创建和断开
    void onConnection(const muduo::net::TcpConnectionPtr& conn) {
        if (conn->connected()) {
            cout << conn->peerAddress().toIpPort() << "->" << conn->localAddress().toIpPort() << endl;
        }
        else {
            cout << conn->peerAddress().toIpPort() << "->" << conn->localAddress().toIpPort() << endl;
            conn->shutdown();
        }
    }
    // 专门处理用户读写事件
    void onMessage(const muduo::net::TcpConnectionPtr& conn,
        muduo::net::Buffer* buf,
        muduo::Timestamp t) {
    }
};

int main(int argc, char const* argv[])
{
    muduo::net::EventLoop loop;
    muduo::net::InetAddress addr("127.0.0.1", 6000);
    ChatServer server(&loop, addr, "CharServer");

    server.start();
    loop.loop();

    return 0;
}
