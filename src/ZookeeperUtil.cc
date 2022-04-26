#include "ZookeeperUtil.h"
#include "MpRpcApplication.h"

// 全局的watcher zkserver给zkclient的通知
void global_watcher(zhandle_t* zh, int type,
    int state, const char* path, void* watcherCtx) {
    // 回调的消息类型和会话相关
    if (type == ZOO_SESSION_EVENT) {
        // 状态连接成功
        if (state == ZOO_CONNECTED_STATE) {
            sem_t* sem = (sem_t*)zoo_get_context(zh);
            sem_post(sem);
        }
    }
}

ZkClient::ZkClient() :m_zhandle(nullptr) {

}

ZkClient::~ZkClient() {
    if (m_zhandle != nullptr) {
        // 关闭句柄
        zookeeper_close(m_zhandle);
    }
}


void ZkClient::start() {
    std::string zk_host = MpRpcApplication::GetInstance().GetConfig().Load("zookeeperip");
    std::string zk_port = MpRpcApplication::GetInstance().GetConfig().Load("zookeeperport");

    std::string conn_str = zk_host + ":" + zk_port;

    // zookeeper 多线程版本
    // 三个线程 
    // 1.api调用线程  
    // 2.网络io线程 poll 
    // 3.watcher回调线程
    m_zhandle = zookeeper_init(conn_str.c_str(), global_watcher, 30000, nullptr, nullptr, 0);
    if (m_zhandle == nullptr) {
        LOG_ERR("zookeeper init error!");
        exit(EXIT_FAILURE);
    }
    sem_t sem;
    sem_init(&sem, 0, 0);
    zoo_set_context(m_zhandle, &sem);

    sem_wait(&sem);
    LOG_INFO("zookeeper init success!");
}


// 创建znode节点
void ZkClient::create(const char* path, const char* data, int datalen, int state) {
    char path_buffer[128];
    int buffer_len = sizeof(path_buffer);
    int flag;
    flag = zoo_exists(m_zhandle, path, 0, nullptr);
    if (flag == ZNONODE) {
        flag = zoo_create(m_zhandle, path, data, datalen,
            &ZOO_OPEN_ACL_UNSAFE, state, path_buffer, buffer_len);
        if (flag == ZOK) {
            LOG_INFO("znode create success ... path : %s", path);
        }
        else {
            LOG_ERR("znode create failed ... path : %s , flag : %d", path, flag);
            exit(EXIT_FAILURE);
        }
    }
}


// 传入参数 根据参数指定的znode节点路径 获取znode节点的值
std::string ZkClient::getData(const char* path) {
    char data_buf[64];
    int buffer_len = sizeof(buffer);
    int flag = zoo_get(m_zhandle, path, 0, data_buf, &buffer_len, nullptr);
    if (flag != ZOK) {
        LOG_ERR("get znode data error ... path : %s", path);
        return "";
    }
    else {
        return data_buf;
    }
}

