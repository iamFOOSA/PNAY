#include "../header /range_exception.h"

RangeException::RangeException(const std::string& msg)
        : Exception(msg.empty() ? get_message() : msg) {}

