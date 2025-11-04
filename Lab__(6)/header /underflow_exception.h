#ifndef UNDERFLOW_EXCEPTION_H
#define UNDERFLOW_EXCEPTION_H

#include "overflow_exception.h"

class UnderflowException : public OverflowException {
public:
    explicit UnderflowException(const std::string& msg);
};

#endif
