#ifndef LAB___3__ABCCATALOG_H
#define LAB___3__ABCCATALOG_H

#include "../header/Catalog.h"

class ABCCatalog : public Catalog {
public:
    ~ABCCatalog();

    void show_all_sorted() const;
};

#endif
