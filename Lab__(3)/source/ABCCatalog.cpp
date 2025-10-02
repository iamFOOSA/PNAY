#include "../header/ABCCatalog.h"
#include <iostream>

using namespace std;


void ABCCatalog::show_all_sorted() const {
    cout << "Все карточки в алфавитном порядке:" << endl;

    if (card_count == 0) {
        cout << "Каталог пуст." << endl;
        return;
    }

    if (card_count <= 0) return;
    auto titles = new string[card_count];

    for (int i = 0; i < card_count; i++) {
        titles[i] = cards[i]->get_alphabetical_search();
    }

    for (int i = 0; i < card_count - 1; i++) {
        for (int j = 0; j < card_count - i - 1; j++) {
            if (j >= 0 && j < card_count - 1 && titles[j] > titles[j + 1]) {
                swap(titles[j], titles[j + 1]);
            }
        }
    }

    for (int i = 0; i < card_count; i++) {
        cout << titles[i] << endl;
    }

    delete[] titles;
}