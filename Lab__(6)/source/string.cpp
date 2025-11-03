#include "../header /string.h"
#include <cstring>
#include <string>

void String::free_memory() {
    if (text != nullptr) {
        delete[] text;
        text = nullptr;
    }
    current_length = 0;
}

void String::copy_from(const char *str, int str_length) {
    if (str_length < 0) {
        throw InvalidArgumentException("Неверная длина строки");
    }

    if (str_length > MAX_LENGTH) {
        throw OverflowTopException("Длина строки превышает максимально допустимую (" +
                                   std::to_string(MAX_LENGTH) + ")");
    }

    text = new(std::nothrow) char[str_length + 1];
    if (text == nullptr) {
        throw MemoryAllocationException("Не удалось выделить память для строки");
    }

    if (str != nullptr && str_length > 0) {
        std::memcpy(text, str, str_length);
    }
    text[str_length] = '\0';
    current_length = str_length;
}

String::String() : text(nullptr), current_length(0) {
    text = new(std::nothrow) char[1];
    if (text == nullptr) {
        throw MemoryAllocationException("Не удалось выделить память для пустой строки");
    }
    text[0] = '\0';
}

String::String(const char *str) : text(nullptr), current_length(0) {
    if (str == nullptr) {
        text = new(std::nothrow) char[1];
        if (text == nullptr) {
            throw MemoryAllocationException("Не удалось выделить память для пустой строки");
        }
        text[0] = '\0';
        current_length = 0;
        return;
    }

    int str_length = static_cast<int>(std::strlen(str));
    copy_from(str, str_length);
}

String::String(const String &other) : text(nullptr), current_length(0) {
    if (other.text == nullptr) {
        text = new(std::nothrow) char[1];
        if (text == nullptr) {
            throw MemoryAllocationException("Не удалось выделить память при копировании");
        }
        text[0] = '\0';
        current_length = 0;
        return;
    }

    int byte_length = static_cast<int>(std::strlen(other.text));
    copy_from(other.text, byte_length);
}

String::~String() {
    free_memory();
}

String &String::operator=(const String &other) {
    if (this == &other) {
        return *this;
    }

    if (other.text == nullptr) {
        free_memory();
        text = new(std::nothrow) char[1];
        if (text == nullptr) {
            throw MemoryAllocationException("Не удалось выделить память при присваивании");
        }
        text[0] = '\0';
        current_length = 0;
        return *this;
    }

    int byte_length = static_cast<int>(std::strlen(other.text));
    copy_from(other.text, byte_length);
    return *this;
}

String &String::operator+=(const String &other) {
    if (other.text == nullptr || other.current_length == 0) {
        return *this;
    }

    int new_length = current_length + other.current_length;

    if (new_length > MAX_LENGTH) {
        throw OverflowTopException("Результат конкатенации превышает максимальную длину (" +
                                   std::to_string(MAX_LENGTH) + ")");
    }

    int current_bytes = (text != nullptr) ? static_cast<int>(std::strlen(text)) : 0;
    int other_bytes = (other.text != nullptr) ? static_cast<int>(std::strlen(other.text)) : 0;
    int new_byte_length = current_bytes + other_bytes;

    char *new_text = new(std::nothrow) char[new_byte_length + 1];
    if (new_text == nullptr) {
        throw MemoryAllocationException("Не удалось выделить память для конкатенации");
    }

    if (current_bytes > 0 && text != nullptr) {
        std::memcpy(new_text, text, current_bytes);
    }

    if (other_bytes > 0 && other.text != nullptr) {
        std::memcpy(new_text + current_bytes, other.text, other_bytes);
    }
    new_text[new_byte_length] = '\0';

    free_memory();
    text = new_text;
    current_length = new_length;

    return *this;
}

bool String::operator==(const String &other) const {
    if (current_length != other.current_length) {
        return false;
    }

    if (text == nullptr && other.text == nullptr) {
        return true;
    }

    if (text == nullptr || other.text == nullptr) {
        return false;
    }

    return std::strcmp(text, other.text) == 0;
}

char &String::operator[](int index) {
    if (index < 0 || index >= current_length || text == nullptr) {
        throw IndexOutOfBoundsException("Индекс " + std::to_string(index) +
                                        " выходит за границы строки (длина: " +
                                        std::to_string(current_length) + ")");
    }
    return text[index];
}

const char &String::operator[](int index) const {
    if (index < 0 || index >= current_length || text == nullptr) {
        throw IndexOutOfBoundsException("Индекс " + std::to_string(index) +
                                        " выходит за границы строки (длина: " +
                                        std::to_string(current_length) + ")");
    }
    return text[index];
}