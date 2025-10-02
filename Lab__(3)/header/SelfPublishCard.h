#ifndef LAB___3__SELFPUBLISHCARD_H
#define LAB___3__SELFPUBLISHCARD_H

#include "../header/libcard.h"
#include <string>

class SelfPublishCard : public LibCard {
private:
    std::string publisher;
    int year;
    int circulation;
    int page_count;

public:
    SelfPublishCard(const std::string &auth, const std::string &titl,
                    const std::string &code, const std::string &publ,
                    int yr, int circ, int pages);

    ~SelfPublishCard() = default;
};

#endif
