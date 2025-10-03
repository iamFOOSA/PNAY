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

    friend std::ostream &operator<<(std::ostream &out, const String &s) {
        size_t i = 0;
        while (s.text[i] != '\0') {
            out << s.text[i];
            ++i;
        }
        return out;
    }

    friend std::istream &operator>>(std::istream &in, String &s) {
        std::string temp;
        in >> temp;
        s = String(temp.c_str());
        return in;
    }
};


#endif
