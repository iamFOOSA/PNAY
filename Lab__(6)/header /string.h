#ifndef STRING_H
#define STRING_H

#include <iostream>
#include "index_out_of_bounds_exception.h"
#include "invalid_argument_exception.h"
#include "overflow_top_exception.h"
#include "memory_allocation_exception.h"

class String {
private:
    char *text = nullptr;
    int current_length=0;
    static const int MAX_LENGTH;
    String *const str1_ptr = nullptr;
    String *const str2_ptr = nullptr;

    void free_memory();

    void copy_from(const char *str, int str_length);

public:
    String();

    explicit String(const char *str);

    String(const String &other);

    ~String();


    String &operator=(const String &other);

    String &operator+=(const String &other);

    bool operator==(const String &other) const;

    char &operator[](int index);

    const char &operator[](int index) const;

    const String *get_str1_ptr() const { return str1_ptr; }

    const String *get_str2_ptr() const { return str2_ptr; }

    friend std::ostream &operator<<(std::ostream &out, const String &s) {
        if (s.text != nullptr) {
            size_t i = 0;
            while (s.text[i] != '\0') {
                out << s.text[i];
                ++i;
            }
        }
        return out;
    }

    friend std::istream &operator>>(std::istream &in, String &s) {
        std::string temp;
        in >> temp;
        s = String(temp.c_str());
        return in;
    }

    int get_length() const { return current_length; }
};

#endif

