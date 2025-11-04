#ifndef INDEX_OUT_OF_BOUNDS_EXCEPTION_H
#define INDEX_OUT_OF_BOUNDS_EXCEPTION_H

#include "range_exception.h"

class IndexOutOfBoundsException : public RangeException {
public:
    explicit IndexOutOfBoundsException(const std::string& msg = "");
    std::string get_message() const override { return "Индекс вне границ"; }
};

#endif

