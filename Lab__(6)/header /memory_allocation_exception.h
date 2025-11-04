#ifndef MEMORY_ALLOCATION_EXCEPTION_H
#define MEMORY_ALLOCATION_EXCEPTION_H

#include "exception.h"

class MemoryAllocationException : public Exception {
public:
    explicit MemoryAllocationException(const std::string& msg);
};

#endif

