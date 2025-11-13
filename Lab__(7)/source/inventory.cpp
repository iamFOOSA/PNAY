#include "../header /inventory.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <array>


void Inventory::load_from_file() {
    product_count = 0;
    std::ifstream file(file_name);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line) && product_count < MAX) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string token;
        std::array<std::string, 4> tokens;
        int token_count = 0;

        while (std::getline(ss, token, '|') && token_count < 4) {
            tokens[token_count] = token;
            token_count++;
        }

        if (token_count == 4) {
            int id = std::stoi(tokens[0]);
            std::string name = tokens[1];
            int quantity = std::stoi(tokens[2]);
            double price = std::stod(tokens[3]);

            products[product_count] = MetalProduct(id, name, quantity, price);
            product_count++;
        }
    }
    file.close();
}

void Inventory::save_to_file() const {
    std::ofstream file(file_name);
    if (!file.is_open()) {
        std::cout << "Ошибка сохранения файла!" << std::endl;
        return;
    }

    for (int i = 0; i < product_count; i++) {
        file << products[i].to_string() << std::endl;
    }
    file.close();
}

int Inventory::find_product_index(int id) const {
    for (int i = 0; i < product_count; i++) {
        if (products[i].id == id) return i;
    }
    return -1;
}

Inventory::Inventory(std::string file_name) : file_name(file_name), product_count(0) {
    load_from_file();
}

Inventory::~Inventory() {
    save_to_file();
}

void Inventory::add_product() {
    if (product_count >= MAX) {
        std::cout << "Склад заполнен!" << std::endl;
        return;
    }

    int id;
    int quantity;
    std::string name;
    double price;

    std::cout << "Введите ID: ";
    std::cin >> id;

    if (find_product_index(id) != -1) {
        std::cout << "Товар с таким ID уже существует!" << std::endl;
        return;
    }

    std::cout << "Введите название: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Введите количество: ";
    std::cin >> quantity;

    std::cout << "Введите цену: ";
    std::cin >> price;

    products[product_count] = MetalProduct(id, name, quantity, price);
    product_count++;
    save_to_file();
    std::cout << "Товар добавлен!" << std::endl;
}

void Inventory::show_all() const {
    if (product_count == 0) {
        std::cout << "Склад пуст!" << std::endl;
        return;
    }

    std::cout << "\n    ВСЕ ТОВАРЫ " << std::endl;
    double total = 0.0;

    for (int i = 0; i < product_count; i++) {
        products[i].display();
        total += products[i].total_value();
    }

    std::cout << "Общая стоимость: " << std::fixed << std::setprecision(2) << total << std::endl;
    std::cout << "Всего товаров: " << product_count << std::endl;
}

void Inventory::find_product() {
    int id;
    std::cout << "Введите ID для поиска: ";
    std::cin >> id;

    int index = find_product_index(id);
    if (index != -1) {
        std::cout << "Найден: ";
        products[index].display();
    } else {
        std::cout << "Товар не найден!" << std::endl;
    }
}


void Inventory::update_product() {
    int id;
    std::cout << "Введите ID для обновления: ";
    std::cin >> id;

    int index = find_product_index(id);
    if (index == -1) {
        std::cout << "Товар не найден!" << std::endl;
        return;
    }

    std::cout << "Текущие данные: ";
    products[index].display();

    int new_quantity;
    double new_price;

    std::cout << "Введите новое количество (текущее: " << products[index].quantity << "): ";
    std::cin >> new_quantity;

    std::cout << "Введите новую цену (текущая: " << products[index].price << "): ";
    std::cin >> new_price;

    products[index].quantity = new_quantity;
    products[index].price = new_price;

    save_to_file();
}

void Inventory::delete_product() {
    int id;
    std::cout << "Введите ID для удаления: ";
    std::cin >> id;

    int index = find_product_index(id);
    if (index == -1) {
        std::cout << "Товар не найден!" << std::endl;
        return;
    }

    products[index].display();

    for (int i = index; i < product_count - 1; i++) {
        products[i] = products[i + 1];
    }
    product_count--;
    save_to_file();
    std::cout << "Товар удален!" << std::endl;
}
