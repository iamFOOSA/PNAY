#include "../header/ABCCatalog.h"
#include <iostream>

void ABCCatalog::show_all_sorted() const {
    std::cout << "Все карточки в алфавитном порядке:" << std::endl;
    int count = get_card_count();

    if (count == 0) {
        std::cout << "Каталог пуст." << std::endl;
        return;
    }

    auto titles = new std::string[count];

    for (int i = 0; i < count; i++) {
        titles[i] = get_card(i)->get_alphabetical_search();
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (titles[j] > titles[j + 1]) {
                std::swap(titles[j], titles[j + 1]);
            }
        }
    }

    for (int i = 0; i < count; i++) {
        std::cout << titles[i] << std::endl;
    }

    delete[] titles;
}