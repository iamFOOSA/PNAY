#ifndef RANGE_EXCEPTION_H
#define RANGE_EXCEPTION_H

#include "exception.h"

class RangeException : public Exception {
public:
    explicit RangeException(const std::string& msg);
};

#endif

