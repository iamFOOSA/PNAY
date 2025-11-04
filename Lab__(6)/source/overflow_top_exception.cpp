#include "../header /overflow_top_exception.h"

OverflowTopException::OverflowTopException(const std::string& msg)
        : OverflowException(msg.empty() ? get_message() : msg) {}

