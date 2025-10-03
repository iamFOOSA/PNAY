#include "../header /string.h"
#include <cstring>

String::String() : text(new char[1]) {
    text[0] = '\0';
}

String::String(const char *str) {
    if (str) {
        size_t len = 0;
        while (str[len] != '\0') ++len;
        text = new char[len + 1];
        for (size_t i = 0; i < len; ++i)
            text[i] = str[i];
        text[len] = '\0';
    } else {
        text = new char[1];
        text[0] = '\0';
    }
}

String::String(const String &other) {
    size_t len = 0;
    while (other.text[len] != '\0') ++len;
    text = new char[len + 1];
    for (size_t i = 0; i < len; ++i)
        text[i] = other.text[i];
    text[len] = '\0';
}

String::~String() {
    delete[] text;
}

String &String::operator=(const String &other) {
    if (this != &other) {
        delete[] text;
        size_t len = 0;
        while (other.text[len] != '\0') ++len;
        text = new char[len + 1];
        for (size_t i = 0; i < len; ++i)
            text[i] = other.text[i];
        text[len] = '\0';
    }
    return *this;
}

String &String::operator+=(const String &other) {
    size_t len1 = 0;
    while (text[len1] != '\0') ++len1;
    size_t len2 = 0;
    while (other.text[len2] != '\0') ++len2;
    auto temp = new char[len1 + len2 + 1];
    for (size_t i = 0; i < len1; ++i)
        temp[i] = text[i];
    for (size_t i = 0; i < len2; ++i)
        temp[len1 + i] = other.text[i];
    temp[len1 + len2] = '\0';
    delete[] text;
    text = temp;
    return *this;
}

bool String::operator==(const String &other) const {
    return std::strcmp(text, other.text) == 0;
}

std::ostream &operator<<(std::ostream &out, const String &s) {
    size_t i = 0;
    while (s.text[i] != '\0') {
        out << s.text[i];
        ++i;
    }
    return out;
}

std::istream &operator>>(std::istream &in, String &s) {
    std::string temp;
    in >> temp;
    s = String(temp.c_str());
    return in;
}
