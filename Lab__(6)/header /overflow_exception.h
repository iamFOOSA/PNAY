#ifndef OVERFLOW_EXCEPTION_H
#define OVERFLOW_EXCEPTION_H

#include "exception.h"

class OverflowException : public Exception {
public:
    explicit OverflowException(const std::string& msg);
};

#endif

