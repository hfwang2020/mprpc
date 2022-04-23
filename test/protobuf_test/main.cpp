/*
//  g++ main.cc test.pb.cc -lprotobuf
//  测试
*/
#include "test.pb.h"
#include <iostream>

using namespace fixbug;

int main() {
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

