#ifndef LAB___7__INVENTORY_H
#define LAB___7__INVENTORY_H


#include "../header /metal_product.h"
#include <string>
#include <array>

class Inventory {
private:
    static const int MAX = 1000;
    std::string file_name;

    std::array<MetalProduct, MAX> products;
    int product_count = 0;

    void load_from_file();

    void save_to_file() const;

    int find_product_index(int id) const;

public:
    explicit Inventory(const std::string& file_name);

    ~Inventory();

    Inventory(const Inventory&) = delete;

    Inventory& operator=(const Inventory&) = delete;

    void add_product();

    void show_all() const;

    void find_product() ;

    void update_product();

    void delete_product();
};

#endif
