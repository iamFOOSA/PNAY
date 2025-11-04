#include "../header /overflow_exception.h"

OverflowException::OverflowException(const std::string& msg)
        : Exception(msg.empty() ? get_message() : msg) {}

