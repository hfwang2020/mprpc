set(SRC_LIST callee.cpp ../user.pb.cc)

add_executable(callee ${SRC_LIST})
target_link_libraries(callee mprpc protobuf)
