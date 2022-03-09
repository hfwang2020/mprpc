#pragma once
#include "MpRpcConfig.h"
#include "MpRpcChannel.h"
#include "MpRpcController.h"
#include "RpcHeader.pb.h"
#include "RpcProvider.h"
#include "MpRpcLogger.h"
#include "ZookeeperUtil.h"

// mprpc框架的基础类 负责框架初始化  单例模式
class MpRpcApplication
{
public:
    static void Init(int argc, char** argv);

    static MpRpcApplication& GetInstance();

    static MpRpcConfig& GetConfig();

private:
    static MpRpcConfig m_config;
    MpRpcApplication() {};
    MpRpcApplication(const MpRpcApplication&) = delete;
    MpRpcApplication(MpRpcApplication&&) = delete;
};