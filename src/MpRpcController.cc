#include "MpRpcController.h"

MpRpcController::MpRpcController() {
    m_failed = false;
    m_errText = "";
}

void MpRpcController::Reset() {
    m_failed = false;
    m_errText = "";
}

bool MpRpcController::Failed() const {
    return m_failed;
}

std::string MpRpcController::ErrorText() const {
    return m_errText;
}

void MpRpcController::SetFailed(const std::string& reason) {
    m_failed = true;
    m_errText = reason;
}

void MpRpcController::StartCancel() {}
bool MpRpcController::IsCanceled() const {
    return false;
}

void MpRpcController::NotifyOnCancel(google::protobuf::Closure* callback) {
    
}

