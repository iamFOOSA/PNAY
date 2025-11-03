#ifndef INDEX_OUT_OF_BOUNDS_EXCEPTION_H
#define INDEX_OUT_OF_BOUNDS_EXCEPTION_H

#include "range_exception.h"

class IndexOutOfBoundsException : public RangeException {
public:
    IndexOutOfBoundsException(const std::string& msg);
};

#endif

