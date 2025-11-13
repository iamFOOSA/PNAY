#include "../header /metal_product.h"
#include <iostream>

MetalProduct::MetalProduct() : id(0), name(""), quantity(0), price(0.0) {}

MetalProduct::MetalProduct(int id, std::string name, int quantity, double price)
        : id(id), name(name), quantity(quantity), price(price) {}

void MetalProduct::display() const {
    std::cout << "ID: " << id << ", Название: " << name
              << ", Количество: " << quantity
              << ", Цена: " << std::fixed << std::setprecision(2) << price
              << ", Общая стоимость: " << std::fixed << std::setprecision(2) << total_value() << std::endl;
}

std::string MetalProduct::to_string() const {
    std::stringstream ss;
    ss << id << "|" << name << "|" << quantity << "|" << std::fixed << std::setprecision(2) << price;
    return ss.str();
}

double MetalProduct::total_value() const {
    return quantity * price;
}