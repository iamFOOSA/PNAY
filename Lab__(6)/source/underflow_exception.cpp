#include "../header /underflow_exception.h"

UnderflowException::UnderflowException(const std::string& msg)
        : OverflowException(msg.empty() ? get_message() : msg) {}

