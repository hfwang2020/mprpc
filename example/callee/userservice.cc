#include <iostream>
#include "user.pb.h"
#include "MpRpcApplication.h"
#include "RpcProvider.h"
#include "google/protobuf/descriptor.h"

/*
UserService原来是一个本地服务，提供两个进程内的本地方法
*/

// 使用在rpc服务发布端
class UserService : public mprpc::UserServiceRpc
{
public:
    bool Login(std::string name, std::string pwd) {
        std::cout << "doing local service : login()" << std::endl;
        std::cout << "name:" << name << " pwd: " << pwd << std::endl;
        return false;
    }
    /*
    重写基类UserServiceRpc的虚函数 下面这些方法都是框架直接调用的
    1. caller ===> login(loginRequest) ==> muduo ==> callee
    2. callee ===> login(request) ==> 交到重写的Login方法上了
    */

    void login(::google::protobuf::RpcController* controller,
        const ::mprpc::LoginRequest* request,
        ::mprpc::LoginResponse* response,
        ::google::protobuf::Closure* done) {
        // 框架给业务上报了请求参数LoginRequest,业务获取相应数据做本地业务
        std::string name = request->name();
        std::string pwd = request->pwd();

        // 做本地业务
        bool login_result = Login(name, pwd);

        // 把响应写入
        response->set_success(login_result);

        ::mprpc::ResultCode* code = response->mutable_result();
        code->set_errcode(0);
        code->set_errmsg(" ");

        // 执行回调操作 执行响应对象数据的序列化和网络发送 都是框架完成
        done->Run();
        
    }
};




// 方法名 方法返回值 序列化
int main(int argc, char** argv) {

    // 调用框架的初始化操作 provider -i config.conf
    MpRpcApplication::Init(argc, argv);

    // provider是一个rpc网络服务对象。把UserService对象发布到rpc节点上。
    // 把UserService对象发布到rpc节点上
    RpcProvider provider;
    provider.NotifyService(new UserService());
    // provider.NotifyService(new ProductService());

    // 启动一个rpc服务发布节点 Run以后进程进入阻塞状态，等待远程rpc调用请求
    provider.Run();
    
    return 0;
}
