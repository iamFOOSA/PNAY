#ifndef LAB___3__CATALOG_H
#define LAB___3__CATALOG_H

#include "../header/libcard.h"

class Catalog {
protected:
    LibCard **cards{};
    int card_count = 0;
    int capacity = 0;

public:
    Catalog();

    ~Catalog();


    void add_card(LibCard *card);

    void search_by_cipher(const string &cipher) const;

    void search_by_author_or_title(const string &search_term) const;
};


#endif
