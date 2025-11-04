#ifndef OVERFLOW_TOP_EXCEPTION_H
#define OVERFLOW_TOP_EXCEPTION_H

#include "overflow_exception.h"

class OverflowTopException : public OverflowException {
public:
    explicit OverflowTopException(const std::string& msg = "");
    std::string get_message() const override { return "Верхнее переполнение"; }
};

#endif

