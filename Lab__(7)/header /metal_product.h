#ifndef LAB___7__METAL_PRODUCT_H
#define LAB___7__METAL_PRODUCT_H


#include <string>
#include <sstream>
#include <iomanip>

struct MetalProduct {
    int id;
    std::string name;
    int quantity;
    double price;

    MetalProduct();

    MetalProduct(int id, const std::string& name, int quantity, double price);

    void display() const;

    std::string to_string() const;

    double total_value() const;
};

#endif
