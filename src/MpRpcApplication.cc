#include "MpRpcApplication.h"
#include <iostream>
#include <unistd.h>

MpRpcConfig  MpRpcApplication::m_config;

void ShowArgsHelp();

void MpRpcApplication::Init(int argc, char** argv) {
    if (argc < 2) {
        ShowArgsHelp();
        exit(EXIT_FAILURE);
    }
    int c = 0;
    std::string config_file;
    while ((c = getopt(argc, argv, "i:")) != -1) {
        switch (c)
        {
        case 'i':
            config_file = optarg;
            // std::cout << "config file name:" << config_file << std::endl;
            break;

        case '?':
            ShowArgsHelp();
            exit(EXIT_FAILURE);

        case ':':
            ShowArgsHelp();
            exit(EXIT_FAILURE);

        default:
            break;
        }
    }
    // 加载配置文件 rpcserverIp port zokper  
    // std::cout << "config file name:" << config_file << std::endl;
    m_config.LoadConfigFile(config_file.c_str());
    // std::cout << m_config.Load("rpcserverip") << std::endl;
    // std::cout << m_config.Load("rpcserverport") << std::endl;

    
}

MpRpcApplication& MpRpcApplication::GetInstance() {
    static MpRpcApplication app;
    return app;
}

MpRpcConfig& MpRpcApplication::GetConfig() {
    return m_config;
}

void ShowArgsHelp() {
    std::cout << "format : command -i <config_file>" << std::endl;
}