#include <iostream>
#include <string>
#include <memory>
#include <locale>
#include "../header /string.h"

inline std::unique_ptr<String> g_str1;
inline std::unique_ptr<String> g_str2;

void create_first_string() {
    std::cout << "\n    Создание первой строки   \n";
    std::string input;
    std::cout << "Введите первую строку: ";
    std::cin.ignore();
    std::getline(std::cin, input);

    try {
        g_str1.reset(new String(input.c_str()));
        const String* const s1 = g_str1.get();
        std::cout << "Первая строка создана: " << *s1 << "\n";
        std::cout << "Длина: " << s1->get_length() << "\n";
    }
    catch (const OverflowTopException& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    catch (const MemoryAllocationException& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    catch (const Exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

void create_second_string() {
    std::cout << "\n     Создание второй строки    \n";
    std::string input;
    std::cout << "Введите вторую строку: ";
    std::cin.ignore();
    std::getline(std::cin, input);
    
    try {
        g_str2.reset(new String(input.c_str()));
        const String* const s2 = g_str2.get();
        std::cout << "Вторая строка создана: " << *s2 << "\n";
        std::cout << "Длина: " << s2->get_length() << "\n";
    }
    catch (const OverflowTopException& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    catch (const MemoryAllocationException& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    catch (const Exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

void view_strings() {
    std::cout << "\n    Просмотр строк    \n";
    
    if (!g_str1) {
        std::cout << "Первая строка не создана\n";
    } else {
        const String* s1 = g_str1.get();
        std::cout << "Первая: \"" << *s1 << "\" (длина: " << s1->get_length() << ")\n";
    }
    
    if (!g_str2) {
        std::cout << "Вторая строка не создана\n";
    } else {
        const String* s2 = g_str2.get();
        std::cout << "Вторая: \"" << *s2 << "\" (длина: " << s2->get_length() << ")\n";
    }

}

void concatenate_strings() {
    std::cout << "\n    Объединение строк   \n";
    
    if (!g_str1 || !g_str2) {
        std::cout << "Ошибка: Строки не созданы!\n";
        return;
    }
    
    String* const s1 = g_str1.get();
    const String* const s2 = g_str2.get();
    std::cout << "Первая: \"" << *s1 << "\" (длина: " << s1->get_length() << ")\n";
    std::cout << "Вторая: \"" << *s2 << "\" (длина: " << s2->get_length() << ")\n";
    
    try {
        *s1 += *s2;
        std::cout << "Результат: \"" << *s1 << "\"\n";
        std::cout << "Длина: " << s1->get_length() << "\n";
    }
    catch (const OverflowTopException& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    catch (const MemoryAllocationException& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    catch (const Exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

void access_by_index() {
    std::cout << "\n    Доступ к символу по индексу   \n";
    
    int string_choice;
    std::cout << "Выберите строку (1 - первая, 2 - вторая): ";
    std::cin >> string_choice;
    
    String* selected_str = nullptr;
    std::string str_name;
    
    if (string_choice == 1) {
        selected_str = g_str1.get();
        str_name = "первая";
    } else if (string_choice == 2) {
        selected_str = g_str2.get();
        str_name = "вторая";
    } else {
        std::cout << "Неверный выбор!\n";
        return;
    }
    
    if (selected_str == nullptr) {
        std::cout << "Ошибка: " << str_name << " строка не создана!\n";
        return;
    }
    
    std::cout << str_name << " строка: \"" << *selected_str << "\"\n";
    std::cout << "Длина: " << selected_str->get_length() << "\n";
    std::cout << "Введите индекс (0-" << (selected_str->get_length() - 1) << "): ";
    
    int index;
    std::cin >> index;
    
    try {
        char ch = (*selected_str)[index];
        std::cout << "Символ по индексу " << index << ": '" << ch << "'\n";
    }
    catch (const IndexOutOfBoundsException& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    catch (const Exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}

void print_menu() {
    std::cout << "       Работа со строками \n";
    std::cout << "1. Создать первую строку \n";
    std::cout << "2. Создать вторую строку  \n";
    std::cout << "3. Просмотреть обе строки  \n";
    std::cout << "4. Объединить строки \n";
    std::cout << "5. Доступ к символу по индексу\n";
    std::cout << "0. Выход  \n";
    std::cout << "Выберите пункт меню: ";
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int choice = -1;
    
    while (choice != 0) {
        print_menu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                create_first_string();
                break;
            case 2:
                create_second_string();
                break;
            case 3:
                view_strings();
                break;
            case 4:
                concatenate_strings();
                break;
            case 5:
                access_by_index();
                break;
            case 0:
                g_str1.reset();
                g_str2.reset();
                break;
            default:
                std::cout << "\nНеверный выбор!\n\n";
                break;
        }
    }
    
    return 0;
}
