#include "../header /index_out_of_bounds_exception.h"

IndexOutOfBoundsException::IndexOutOfBoundsException(const std::string& msg)
        : RangeException(msg.empty() ? get_message() : msg) {}

