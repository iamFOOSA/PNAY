#ifndef UNDERFLOW_EXCEPTION_H
#define UNDERFLOW_EXCEPTION_H

#include "overflow_exception.h"

class UnderflowException : public OverflowException {
public:
    UnderflowException(const std::string& msg);
};

#endif
