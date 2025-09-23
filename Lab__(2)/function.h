#ifndef LAB___2__FUNCTION_H
#define LAB___2__FUNCTION_H

#include <iostream>
#include <cstring>

class String {
    char *text;

public:
    String();

    explicit String(const char *str);

    String(const String &other);

    ~String();

    String &operator=(const String &other);

    String &operator+=(const String &other);

    bool operator==(const String &other) const {
        size_t i = 0;
        while (text[i] != '\0' && other.text[i] != '\0') {
            if (text[i] != other.text[i])
                return false;
            ++i;
        }
        return text[i] == '\0' && other.text[i] == '\0';
    }

    friend std::istream &operator>>(std::istream &in, String &s) {
        std::string temp;
        in >> temp;
        s = String(temp.c_str());
        return in;
    }
};

void ShowMenu();

#endif
