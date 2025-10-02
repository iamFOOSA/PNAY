#include "../header/Catalog.h"
#include <iostream>

Catalog::Catalog()  {}

Catalog::~Catalog() {
    for (int i = 0; i < card_count; i++) {
        delete cards[i];
    }
    delete[] cards;
}

Catalog::Catalog(Catalog&& other) noexcept
        : capacity(other.capacity),
          cards(other.cards),
          card_count(other.card_count) {
    other.cards = nullptr;
    other.card_count = 0;
    other.capacity = 0;
}

Catalog& Catalog::operator=(Catalog&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < card_count; i++) {
            delete cards[i];
        }
        delete[] cards;

        cards = other.cards;
        card_count = other.card_count;
        capacity = other.capacity;

        other.cards = nullptr;
        other.card_count = 0;
        other.capacity = 0;
    }
    return *this;
}

void Catalog::add_card(LibCard* card) {
    if (card_count >= capacity) {
        int new_capacity = (capacity == 0) ? 2 : capacity * 2;

        if (new_capacity <= card_count) {
            new_capacity = card_count + 1;
        }

        auto new_cards = new LibCard *[new_capacity];
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

void Catalog::search_by_cipher(const std::string& cipher) const {
    std::cout << "Поиск по шифру '" << cipher << "':" << std::endl;
    bool found = false;

    for (int i = 0; i < card_count; i++) {
        if (cards[i]->get_thematic_code() == cipher) {
            std::cout << "Найдено: " << cards[i]->get_alphabetical_search() << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Ничего не найдено." << std::endl;
    }
}

void Catalog::search_by_author_or_title(const std::string& search_term) const {
    std::cout << "Поиск '" << search_term << "':" << std::endl;
    bool found = false;

    for (int i = 0; i < card_count; i++) {
        if (cards[i]->get_author().contains(search_term) ||
            cards[i]->get_title().contains(search_term)) {
            std::cout << "Найдено: " << cards[i]->get_alphabetical_search() << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "Ничего не найдено." << std::endl;
    }
}