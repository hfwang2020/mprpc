/*
//  g++ main.cc test.pb.cc -lprotobuf
//  测试
*/
#include "test.pb.h"
#include <iostream>

using namespace fixbug;


int main() {
    
    // // 封装了login请求对象的数据
    // LoginRequest req;
    // req.set_name("zhangsan");
    // req.set_pwd("123456");

    // // 对象数据序列化
    // std::string send_str;
    // req.SerializeToString(&send_str);
    // std::cout << send_str << std::endl;


    // // 反序列化
    // LoginRequest reqB;
    // reqB.ParseFromString(send_str);
    // std::cout << reqB.name() << std::endl;
    // std::cout << reqB.pwd() << std::endl;
    // LoginResponse rsp;
    // ResultCode* rc = rsp.mutable_result();
    // rc->set_errcode(1);
    // rc->set_errmsg("error");

    GetFriendListsResponse rsp;
    ResultCode* rc = rsp.mutable_result();
    rc->set_errcode(0);

    User* user1 = rsp.add_friend_list();
    user1->set_name("zhang san");
    user1->set_age(20);
    user1->set_sex(User::MAN);

    User* user2 = rsp.add_friend_list();
    user1->set_name("zhang san");
    user1->set_age(20);
    user1->set_sex(User::MAN);

    std::cout << rsp.friend_list_size() << std::endl;
    
}

