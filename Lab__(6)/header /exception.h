#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception {
private:
    std::string message;



public:
    explicit Exception(const std::string& msg);
    virtual ~Exception() = default;
    virtual const char* what() const noexcept;
};

#endif

