#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception {
private:
    std::string message;

public:
    explicit Exception(const std::string& msg);
    virtual ~Exception() = default;
    const char* what() const noexcept;

    virtual std::string get_message() const { return "Ошибка"; }
};

#endif

