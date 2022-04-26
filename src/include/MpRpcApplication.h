#pragma once
#include "MpRpcConfig.h"
#include "MpRpcChannel.h"
#include "MpRpcLogger.h"
#include "MpRpcChannel.h"
#include "RpcHeader.pb.h"
#include "RpcProvider.h"
#include "ZookeeperUtil.h"


class MpRpcApplication {
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