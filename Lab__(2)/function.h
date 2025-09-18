#ifndef LAB___2__FUNCTION_H
#define LAB___2__FUNCTION_H

#include <iostream>
#include <cstring>

class String {
    char *text;

public:
    String();
    String(const char *str);
    String(const String &other);
    ~String();

    String& operator=(const String &other);
    String& operator+=(const String &other);
    bool operator==(const String &other) const;

    friend std::ostream& operator<<(std::ostream &out, const String &str);
    friend std::istream& operator>>(std::istream &in, String &str);
};

void ShowMenu();

#endif
