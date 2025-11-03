#include <iostream>
#include <string>
#include <locale>
#include "string.h"
#include "exception.h"
#include "index_out_of_bounds_exception.h"
#include "overflow_top_exception.h"
#include "memory_allocation_exception.h"

String* str1_ptr = nullptr;
String* str2_ptr = nullptr;

void create_first_string() {
    std::cout << "\n=== СОЗДАНИЕ ПЕРВОЙ СТРОКИ ===\n";
    std::string input;
    std::cout << "Введите первую строку: ";
    std::cin.ignore();
    std::getline(std::cin, input);
    
    try {
        if (str1_ptr != nullptr) {
            delete str1_ptr;
        }
        str1_ptr = new String(input.c_str());
        std::cout << "Первая строка создана: " << *str1_ptr << "\n";
        std::cout << "Длина: " << str1_ptr->get_length() << "\n";
    }
    catch (const OverflowTopException& e) {
        std::cout << "ОШИБКА: " << e.what() << std::endl;
    }
    catch (const MemoryAllocationException& e) {
        std::cout << "ОШИБКА: " << e.what() << std::endl;
    }
    catch (const Exception& e) {
        std::cout << "ОШИБКА: " << e.what() << std::endl;
    }
    std::cout << "================================\n\n";
}

void create_second_string() {
    std::cout << "\n=== СОЗДАНИЕ ВТОРОЙ СТРОКИ ===\n";
    std::string input;
    std::cout << "Введите вторую строку: ";
    std::cin.ignore();
    std::getline(std::cin, input);
    
    try {
        if (str2_ptr != nullptr) {
            delete str2_ptr;
        }
        str2_ptr = new String(input.c_str());
        std::cout << "Вторая строка создана: " << *str2_ptr << "\n";
        std::cout << "Длина: " << str2_ptr->get_length() << "\n";
    }
    catch (const OverflowTopException& e) {
        std::cout << "ОШИБКА: " << e.what() << std::endl;
    }
    catch (const MemoryAllocationException& e) {
        std::cout << "ОШИБКА: " << e.what() << std::endl;
    }
    catch (const Exception& e) {
        std::cout << "ОШИБКА: " << e.what() << std::endl;
    }
    std::cout << "================================\n\n";
}

void view_strings() {
    std::cout << "\n=== ПРОСМОТР СТРОК ===\n";
    
    if (str1_ptr == nullptr) {
        std::cout << "Первая строка не создана\n";
    } else {
        std::cout << "Первая: \"" << *str1_ptr << "\" (длина: " << str1_ptr->get_length() << ")\n";
    }
    
    if (str2_ptr == nullptr) {
        std::cout << "Вторая строка не создана\n";
    } else {
        std::cout << "Вторая: \"" << *str2_ptr << "\" (длина: " << str2_ptr->get_length() << ")\n";
    }
    
    std::cout << "======================\n\n";
}

void concatenate_strings() {
    std::cout << "\n=== ОБЪЕДИНЕНИЕ СТРОК ===\n";
    
    if (str1_ptr == nullptr || str2_ptr == nullptr) {
        std::cout << "ОШИБКА: Строки не созданы!\n";
        std::cout << "==========================\n\n";
        return;
    }
    
    std::cout << "Первая: \"" << *str1_ptr << "\" (длина: " << str1_ptr->get_length() << ")\n";
    std::cout << "Вторая: \"" << *str2_ptr << "\" (длина: " << str2_ptr->get_length() << ")\n";
    
    try {
        *str1_ptr += *str2_ptr;
        std::cout << "Результат: \"" << *str1_ptr << "\"\n";
        std::cout << "Длина: " << str1_ptr->get_length() << "\n";
    }
    catch (const OverflowTopException& e) {
        std::cout << "ОШИБКА: " << e.what() << std::endl;
    }
    catch (const MemoryAllocationException& e) {
        std::cout << "ОШИБКА: " << e.what() << std::endl;
    }
    catch (const Exception& e) {
        std::cout << "ОШИБКА: " << e.what() << std::endl;
    }
    std::cout << "==========================\n\n";
}

void access_by_index() {
    std::cout << "\n=== ДОСТУП К СИМВОЛУ ПО ИНДЕКСУ ===\n";
    
    int string_choice;
    std::cout << "Выберите строку (1 - первая, 2 - вторая): ";
    std::cin >> string_choice;
    
    String* selected_str = nullptr;
    std::string str_name;
    
    if (string_choice == 1) {
        selected_str = str1_ptr;
        str_name = "первая";
    } else if (string_choice == 2) {
        selected_str = str2_ptr;
        str_name = "вторая";
    } else {
        std::cout << "Неверный выбор!\n";
        std::cout << "=====================================\n\n";
        return;
    }
    
    if (selected_str == nullptr) {
        std::cout << "ОШИБКА: " << str_name << " строка не создана!\n";
        std::cout << "=====================================\n\n";
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
        std::cout << "ОШИБКА: " << e.what() << std::endl;
    }
    catch (const Exception& e) {
        std::cout << "ОШИБКА: " << e.what() << std::endl;
    }
    std::cout << "=====================================\n\n";
}

void print_menu() {
    std::cout << "\n╔════════════════════════════════════════════════════════╗\n";
    std::cout << "║              РАБОТА СО СТРОКАМИ                        ║\n";
    std::cout << "╠════════════════════════════════════════════════════════╣\n";
    std::cout << "║  1. Создать первую строку                             ║\n";
    std::cout << "║  2. Создать вторую строку                             ║\n";
    std::cout << "║  3. Просмотреть обе строки                             ║\n";
    std::cout << "║  4. Объединить строки (первая += вторая)              ║\n";
    std::cout << "║  5. Доступ к символу по индексу                       ║\n";
    std::cout << "║  0. Выход                                               ║\n";
    std::cout << "╚════════════════════════════════════════════════════════╝\n";
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
                if (str1_ptr != nullptr) {
                    delete str1_ptr;
                }
                if (str2_ptr != nullptr) {
                    delete str2_ptr;
                }
                break;
            default:
                std::cout << "\nНеверный выбор!\n\n";
                break;
        }
    }
    
    return 0;
}
