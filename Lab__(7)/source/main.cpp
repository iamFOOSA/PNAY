#include <iostream>
#include <locale>
#include "../header /inventory.h"


using namespace std;

void display_menu() {
    cout << "\n   МЕНЮ" << endl;
    cout << "1. Добавить изделие" << endl;
    cout << "2. Показать все изделия" << endl;
    cout << "3. Найти изделие" << endl;
    cout << "4. Обновить изделие" << endl;
    cout << "5. Удалить изделие" << endl;
    cout << "0. Выйти" << endl;
    cout << "Выберите опцию: ";
}

int main() {
    setlocale(LC_ALL, "Russian");

    string file_name = "inventory.txt";
    Inventory inventory(file_name);

    int choice;

    do {
        display_menu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n    Добавление нового изделия " << endl;
                inventory.add_product();
                break;

            case 2:
                cout << "\n    Список всех изделий " << endl;
                inventory.show_all();
                break;

            case 3:
                cout << "\n    Поиск изделия " << endl;
                inventory.find_product();
                break;

            case 4:
                cout << "\n   Обновление изделия" << endl;
                inventory.update_product();
                break;

            case 5:
                cout << "\n    Удаление изделия " << endl;
                inventory.delete_product();
                break;

            case 0:
                cout << "Выход из программы." << endl;
                break;

            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
        }
    } while (choice != 0);

    return 0;
}