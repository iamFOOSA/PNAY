#ifndef OVERFLOW_TOP_EXCEPTION_H
#define OVERFLOW_TOP_EXCEPTION_H

#include "overflow_exception.h"

class OverflowTopException : public OverflowException {
public:
    OverflowTopException(const std::string& msg);
};

#endif

