#include "MpRpcLogger.h"
#include "time.h"
#include "unistd.h"
#include <iostream>

MpRpcLogger& MpRpcLogger::GetInstance() {
    static MpRpcLogger logger;
    return logger;
}

void MpRpcLogger::SetLogLevel(LogLevel level) {
    m_loglevel = level;
}

void MpRpcLogger::log(std::string msg) {
    m_logqueue.push(msg);
}

MpRpcLogger::MpRpcLogger() {
    // 专门写日志的线程
    std::thread writeLogTask([&]() {
        for (;;) {
            // 获取当前的日期，取日志信息，写入日志
            time_t now = time(nullptr);
            tm* now_tm = localtime(&now);
            char file_name[128];
            sprintf(file_name, "MpRPC-%d-%d-%d.log", now_tm->tm_year + 1900, now_tm->tm_mon + 1, now_tm->tm_mday);
            FILE* pf = fopen(file_name, "a+");
            if (pf == nullptr) {
                std::cout << "logger file : " << file_name << " open error!" << std::endl;
                exit(EXIT_FAILURE);
            }
            std::string msg = m_logqueue.pop();

            char time_buf[128] = { 0 };
            sprintf(time_buf, "[%s] %d:%d:%d => ", (m_loglevel == INFO ? "INFO" : "ERROR"),
                now_tm->tm_hour, now_tm->tm_min, now_tm->tm_sec);

            msg.insert(0, time_buf);
            msg.append("\n");
            fputs(msg.c_str(), pf);
            fclose(pf);
        }
        });
    // 设置分离线程 守护进程
    writeLogTask.detach();
}
