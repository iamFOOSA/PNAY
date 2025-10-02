#include "../header/Catalog.h"
#include <iostream>

using namespace std;

Catalog::Catalog() : cards(nullptr), card_count(0), capacity(0) {}

Catalog::~Catalog() {
    for (int i = 0; i < card_count; i++) {
        delete cards[i];
    }
    delete[] cards;
}

void Catalog::add_card(LibCard *card) {
    if (card_count >= capacity) {
        int new_capacity = (capacity == 0) ? 2 : capacity * 2;
        LibCard **new_cards = new LibCard *[new_capacity];

        for (int i = 0; i < card_count; i++) {
            new_cards[i] = cards[i];
        }

        delete[] cards;
        cards = new_cards;
        capacity = new_capacity;
    }

    cards[card_count] = card;
    card_count++;
}

void Catalog::search_by_cipher(const string &cipher) const {
    cout << "Поиск по шифру '" << cipher << "':" << endl;
    bool found = false;

    for (int i = 0; i < card_count; i++) {
        if (cards[i]->get_thematic_code() == cipher) {
            cout << "Найдено: " << cards[i]->get_alphabetical_search() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Ничего не найдено." << endl;
    }
}

void Catalog::search_by_author_or_title(const string &search_term) const {
    cout << "Поиск '" << search_term << "':" << endl;
    bool found = false;

    for (int i = 0; i < card_count; i++) {
        if (cards[i]->get_author().find(search_term) != string::npos ||
            cards[i]->get_title().find(search_term) != string::npos) {
            cout << "Найдено: " << cards[i]->get_alphabetical_search() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Ничего не найдено." << endl;
    }
}