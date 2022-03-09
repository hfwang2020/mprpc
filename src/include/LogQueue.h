#pragma once

#include <queue>
#include <thread>
// pthread_mutex_t
#include <mutex> 
// pthread_condition_t
#include <condition_variable>

// 异步写日志的日志队列 
// 基于queue改造线程安全
// 模板只能在头文件中写
template <typename T>
class LogQueue {
public:
    // 多个工作线程push
    void push(const T& data) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_queue.push(data);
        m_cond.notify_one();
    }
    // 一个线程pop
    T pop() {
        std::unique_lock<std::mutex> lock(m_mutex);
        while (m_queue.empty()) {
            // 日志队列为空
            // 线程进入wait状态
            m_cond.wait(lock);
        }
        T data = m_queue.front();
        m_queue.pop();
        return data;
    }
    
private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_cond;
};

