#ifndef LAB___2__STRING_H
#define LAB___2__STRING_H

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

    friend std::ostream &operator<<(std::ostream &out, const String &s);

    friend std::istream &operator>>(std::istream &in, String &s);
};


#endif
