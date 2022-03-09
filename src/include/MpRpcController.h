#pragma once
#include <google/protobuf/service.h>
#include <string>


class MpRpcController : public google::protobuf::RpcController {
public:
    MpRpcController();
    void Reset();
    bool Failed() const;
    std::string ErrorText() const;
    void SetFailed(const std::string& reason);

    // 
    void StartCancel();
    bool IsCanceled() const;
    void NotifyOnCancel(google::protobuf::Closure*);

private:
    bool m_failed;
    std::string m_errText;
};