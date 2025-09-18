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

    bool operator==(const String &other) const;

    friend std::ostream &operator<<(std::ostream &out, const String &str) {
        out << str.text;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, String &str) {
        std::string temp;
        in >> temp;  // безопасный ввод, без ограничения длины
        delete[] str.text;
        str.text = new char[temp.size() + 1];
        std::memcpy(str.text, temp.c_str(), temp.size() + 1);
        return in;
    }
};

void ShowMenu();

#endif
