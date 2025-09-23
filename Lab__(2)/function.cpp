#include "function.h"


String::String() : text(new char[1]) {
    text[0] = '\0';
}


String::String(const char *str) {
    if (str) {
        size_t len = std::strlen(str);
        text = new char[len + 1];
        std::strncpy(text, str, len);
        text[len] = '\0';
    } else {
        text = new char[1];
        text[0] = '\0';
    }
}

String::String(const String &other) {
    size_t len = std::strlen(other.text);
    text = new char[len + 1];
    std::strncpy(text, other.text, len);
    text[len] = '\0';
}

String::~String() {
    delete[] text;
}

String &String::operator=(const String &other) {
    if (this != &other) {
        delete[] text;
        size_t len = std::strlen(other.text);
        text = new char[len + 1];
        std::strncpy(text, other.text, len);
        text[len] = '\0';
    }
    return *this;
}

String &String::operator+=(const String &other) {
    size_t len1 = std::strlen(text);
    size_t len2 = std::strlen(other.text);
    char *temp = new char[len1 + len2 + 1];
    std::strncpy(temp, text, len1);
    temp[len1] = '\0';
    std::strncat(temp, other.text, len2);
    temp[len1 + len2] = '\0';
    delete[] text;
    text = temp;
    return *this;
}

bool String::operator==(const String &other) const {
    return std::strcmp(text, other.text) == 0;
}

void ShowMenu() {
    String s1;
    String s2;
    int choice;

    do {
        std::cout << "\n    MENU    \n";
        std::cout << "1. Input first string\n";
        std::cout << "2. Display first string\n";
        std::cout << "3. Display second string\n";
        std::cout << "4. Assign first string to second\n";
        std::cout << "5. Add second string to first\n";
        std::cout << "6. Check if strings are equal\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose point: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter first string: ";
                std::cin >> s1;
                break;
            case 2:
                std::cout << "First string: " << s1 << std::endl;
                break;
            case 3:
                std::cout << "Second string: " << s2 << std::endl;
                break;
            case 4:
                s2 = s1;
                std::cout << "Second string contains the first string.\n";
                break;
            case 5:
                s1 += s2;
                std::cout << "First string after adding second: " << s1 << std::endl;
                break;
            case 6:
                if (s1 == s2)
                    std::cout << "Strings are equal.\n";
                else
                    std::cout << "Strings are different.\n";
                break;
            case 0:
                std::cout << "Exit program.\n";
                break;
            default:
                std::cout << "ERROR. Try again.\n";
        }
    } while (choice != 0);
}