#include "../header/ABCCatalog.h"
#include <iostream>

using namespace std;

ABCCatalog::~ABCCatalog() {
}

void ABCCatalog::show_all_sorted() const {
    cout << "Все карточки в алфавитном порядке:" << endl;

    string *titles = new string[card_count];
    for (int i = 0; i < card_count; i++) {
        titles[i] = cards[i]->get_alphabetical_search();
    }

    for (int i = 0; i < card_count - 1; i++) {
        for (int j = 0; j < card_count - i - 1; j++) {
            if (titles[j] > titles[j + 1]) {
                string temp = titles[j];
                titles[j] = titles[j + 1];
                titles[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < card_count; i++) {
        cout << "  " << (i + 1) << ". " << titles[i] << endl;
    }

    delete[] titles;
}