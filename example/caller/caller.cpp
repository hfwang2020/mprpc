#include <iostream>
#include "user.pb.h"
#include "MpRpcApplication.h"
#include "MpRpcLogger.h"
#include "MpRpcController.h"


int main(int argc, char* argv[])
{

    LOG_ERR("first log");

    MpRpcApplication::Init(argc, argv);

    mprpc::UserServiceRpc_Stub stub(new MpRpcChannel());

    mprpc::LoginRequest request;
    request.set_name("hfwang1111");
    request.set_pwd("passwd");

    mprpc::LoginResponse response;


    MpRpcController controller;
    stub.login(&controller, &request, &response, nullptr);

    if (controller.Failed()) {
        std::cout << controller.ErrorText() << std::endl;
        return 0;
    }
    std::cout << "response error code : " << response.result().errcode() << std::endl;
    std::cout << "success code :" << response.success() << std::endl;
    if (response.result().errcode() == 0) {
        std::cout << "rpc login response success !" << std::endl;
    }
    else {
        std::cout << "rpc login response failed !" << std::endl;
    }
    
    return 0;
}





