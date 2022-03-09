#pragma once

#include <semaphore.h>
#include <zookeeper/zookeeper.h>
#include <string>

// 封装的zk客户端类
class ZkClient {
public:
    ZkClient();
    ~ZkClient();
    // 
    void start();
    // 创建znode节点
    void create(const char* path, const char* data, int datalen, int state = 0);
    // 传入参数 根据参数指定的znode节点路径 或者znode节点的值
    std::string getData(const char* path);
private:
    // zk的客户端句柄
    zhandle_t* m_zhandle;
};



