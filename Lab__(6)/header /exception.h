#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception {
private:
    std::string message;

public:
    explicit Exception(const std::string& msg);
    ~Exception() = default;
    const char* what() const noexcept;
};

#endif

