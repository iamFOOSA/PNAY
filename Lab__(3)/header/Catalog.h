#ifndef LAB___3__CATALOG_H
#define LAB___3__CATALOG_H

#include "../header/libcard.h"
#include <string>

class Catalog {
private:
    LibCard **cards;
    int card_count;
    int capacity;

public:
    Catalog();

    ~Catalog();

    Catalog(const Catalog &) = delete;

    Catalog &operator=(const Catalog &) = delete;

    Catalog(Catalog &&other) noexcept;

    Catalog &operator=(Catalog &&other) noexcept;

    void add_card(LibCard *card);

    void search_by_cipher(const std::string &cipher) const;

    void search_by_author_or_title(const std::string &search_term) const;
};


#endif
