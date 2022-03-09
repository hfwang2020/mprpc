#pragma once
#include "LogQueue.h"
// MpRpc 日志系统
// 定义日志宏 
#define LOG_INFO(logmsgformat, ...) \
    do                                                      \
    {                                                       \
        MpRpcLogger& logger = MpRpcLogger::GetInstance();   \
        logger.SetLogLevel(INFO);                           \
        char c[1024] = {0};                                 \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__);     \
        logger.log(c);                                      \
    }                                                       \
    while (0);                                          

#define LOG_ERR(logmsgformat, ...) \
    do                                                      \
    {                                                       \
        MpRpcLogger& logger = MpRpcLogger::GetInstance();   \
        logger.SetLogLevel(ERROR);                          \
        char c[1024] = {0};                                 \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__);     \
        logger.log(c);                                      \
    }                                                       \
    while (0);                                          


enum LogLevel
{
    INFO,
    ERROR,
};

class MpRpcLogger
{
public:
    static MpRpcLogger& GetInstance();
    // 设置日志级别
    void SetLogLevel(LogLevel level);
    void log(std::string);

private:
    int m_loglevel;
    LogQueue<std::string> m_logqueue;

    MpRpcLogger();
    MpRpcLogger(const MpRpcLogger&) = delete;
    MpRpcLogger(MpRpcLogger&&) = delete;
};
