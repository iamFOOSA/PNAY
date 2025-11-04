#include "../header /memory_allocation_exception.h"

MemoryAllocationException::MemoryAllocationException(const std::string& msg)
        : Exception(msg.empty() ? get_message() : msg) {}


