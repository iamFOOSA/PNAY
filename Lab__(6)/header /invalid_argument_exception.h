#ifndef INVALID_ARGUMENT_EXCEPTION_H
#define INVALID_ARGUMENT_EXCEPTION_H

#include "exception.h"

class InvalidArgumentException : public Exception {
public:
    explicit InvalidArgumentException(const std::string& msg);
};

#endif

