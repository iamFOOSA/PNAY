#include "../header /string.h"
#include <cstring>
#include <string>
#include <format>

const int String::MAX_LENGTH = 50;


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
        throw OverflowTopException(std::format("Длина строки превышает максимально допустимую ({})", MAX_LENGTH));
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

String::String() {
    text = new(std::nothrow) char[1];
    if (text == nullptr) {
        throw MemoryAllocationException("Не удалось выделить память");
    }
    text[0] = '\0';
}

String::String(const char *str) {
    if (str == nullptr) {
        text = new(std::nothrow) char[1];
        if (text == nullptr) {
            throw MemoryAllocationException("Не удалось выделить память");
        }
        text[0] = '\0';
        current_length = 0;
        return;
    }

    int str_length = 0;
    while (str[str_length] != '\0' && str_length <= MAX_LENGTH) {
        str_length++;
    }
    copy_from(str, str_length);
}

String::String(const String &other) {
    if (other.text == nullptr) {
        text = new(std::nothrow) char[1];
        if (text == nullptr) {
            throw MemoryAllocationException("Не удалось выделить память");
        }
        text[0] = '\0';
        current_length = 0;
        return;
    }

    int byte_length = 0;
    while (other.text[byte_length] != '\0' && byte_length <= MAX_LENGTH) {
        byte_length++;
    }
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
            throw MemoryAllocationException("Не удалось выделить память");
        }
        text[0] = '\0';
        current_length = 0;
        return *this;
    }

    int byte_length = 0;
    while (other.text[byte_length] != '\0' && byte_length <= MAX_LENGTH) {
        byte_length++;
    }
    copy_from(other.text, byte_length);
    return *this;
}

String &String::operator+=(const String &other) {
    if (other.text == nullptr || other.current_length == 0) {
        return *this;
    }

    int new_length = current_length + other.current_length;

    if (new_length > MAX_LENGTH) {
        throw OverflowTopException(std::format("Результат объединения превышает максимальную длину ({})", MAX_LENGTH));  // исправить текст
    }

    int current_bytes = 0;
    if (text != nullptr) {
        while (text[current_bytes] != '\0' && current_bytes <= MAX_LENGTH) {
            current_bytes++;
        }
    }

    int other_bytes = 0;
    if (other.text != nullptr) {
        while (other.text[other_bytes] != '\0' && other_bytes <= MAX_LENGTH) {
            other_bytes++;
        }
    }

    int new_byte_length = current_bytes + other_bytes;

    auto new_text = new(std::nothrow) char[new_byte_length + 1];
    if (new_text == nullptr) {
        throw MemoryAllocationException("Не удалось выделить память");
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

    int i = 0;
    while (text[i] != '\0' && other.text[i] != '\0' && i <= MAX_LENGTH) {
        if (text[i] != other.text[i]) {
            return false;
        }
        i++;
    }
    return text[i] == other.text[i];
}

char &String::operator[](int index) {
    if (index < 0 || index >= current_length || text == nullptr) {
        throw IndexOutOfBoundsException(std::format("Индекс {} выходит за границы строки (длина: {})", index, current_length));

    }
    return text[index];
}

const char &String::operator[](int index) const {
    if (index < 0 || index >= current_length || text == nullptr) {
        throw IndexOutOfBoundsException(std::format("Индекс {} выходит за границы строки (длина: {})", index, current_length));

    }
    return text[index];
}