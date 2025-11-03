#include "../header /string.h"
#include "../header /memory_allocation_exception.h"
#include "../header /index_out_of_bounds_exception.h"
#include "../header /invalid_argument_exception.h"
#include "../header /overflow_top_exception.h"
#include <cstring>
#include <string>

static int count_utf8_chars(const char *str, int byte_length) {
    int char_count = 0;
    for (int i = 0; i < byte_length; ) {
        unsigned char byte = static_cast<unsigned char>(str[i]);
        if (byte < 0x80) {
            i++;
        } else if ((byte & 0xE0) == 0xC0) {
            i += 2;
        } else if ((byte & 0xF0) == 0xE0) {
            i += 3;
        } else if ((byte & 0xF8) == 0xF0) {
            i += 4;
        } else {
            i++;
        }
        char_count++;
    }
    return char_count;
}

void String::free_memory() {
    if (text != nullptr) {
        delete[] text;
        text = nullptr;
    }
    current_length = 0;
}

void String::copy_from(const char *str, int byte_length) {
    if (byte_length < 0) {
        throw InvalidArgumentException("Неверная длина строки");
    }
    
    int char_count = count_utf8_chars(str, byte_length);
    
    if (char_count > MAX_LENGTH) {
        throw OverflowTopException("Длина строки превышает максимально допустимую (" + 
                                   std::to_string(MAX_LENGTH) + ")");
    }

    text = new(std::nothrow) char[byte_length + 1];
    if (text == nullptr) {
        throw MemoryAllocationException("Не удалось выделить память для строки");
    }

    std::memcpy(text, str, byte_length);
    text[byte_length] = '\0';
    current_length = char_count;
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
    
    int str_length = std::strlen(str);
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
    
    int byte_length = std::strlen(other.text);
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
    
    int byte_length = std::strlen(other.text);
    copy_from(other.text, byte_length);
    return *this;
}

String &String::operator+=(const String &other) {
    if (other.text == nullptr || other.current_length == 0) {
        return *this;
    }
    
    int new_char_count = current_length + other.current_length;
    
    if (new_char_count > MAX_LENGTH) {
        throw OverflowTopException("Результат конкатенации превышает максимальную длину (" + 
                                   std::to_string(MAX_LENGTH) + ")");
    }
    
    int current_bytes = (text != nullptr) ? std::strlen(text) : 0;
    int other_bytes = std::strlen(other.text);
    int new_byte_length = current_bytes + other_bytes;
    
    char *new_text = new(std::nothrow) char[new_byte_length + 1];
    if (new_text == nullptr) {
        throw MemoryAllocationException("Не удалось выделить память для конкатенации");
    }

    if (current_bytes > 0 && text != nullptr) {
        std::memcpy(new_text, text, current_bytes);
    }

    std::memcpy(new_text + current_bytes, other.text, other_bytes);
    new_text[new_byte_length] = '\0';
    
    free_memory();
    text = new_text;
    current_length = new_char_count;
    
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

static int find_char_byte_position(const char *str, int char_index) {
    int char_count = 0;
    int i = 0;
    while (str[i] != '\0' && char_count < char_index) {
        unsigned char byte = static_cast<unsigned char>(str[i]);
        if (byte < 0x80) {
            i++;
        } else if ((byte & 0xE0) == 0xC0) {
            i += 2;
        } else if ((byte & 0xF0) == 0xE0) {
            i += 3;
        } else if ((byte & 0xF8) == 0xF0) {
            i += 4;
        } else {
            i++;
        }
        char_count++;
    }
    return i;
}

char &String::operator[](int index) {
    if (index < 0 || index >= current_length || text == nullptr) {
        throw IndexOutOfBoundsException("Индекс " + std::to_string(index) + 
                                       " выходит за границы строки (длина: " + 
                                       std::to_string(current_length) + ")");
    }
    int byte_pos = find_char_byte_position(text, index);
    return text[byte_pos];
}

const char &String::operator[](int index) const {
    if (index < 0 || index >= current_length || text == nullptr) {
        throw IndexOutOfBoundsException("Индекс " + std::to_string(index) + 
                                       " выходит за границы строки (длина: " + 
                                       std::to_string(current_length) + ")");
    }
    int byte_pos = find_char_byte_position(text, index);
    return text[byte_pos];
}
