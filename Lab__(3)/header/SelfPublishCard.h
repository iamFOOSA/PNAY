#ifndef LAB___3__SELFPUBLISHCARD_H
#define LAB___3__SELFPUBLISHCARD_H

#include "../header/libcard.h"
#include <string>

using namespace std;

class SelfPublishCard : public LibCard {
protected:
    string publisher;
    int year;
    int circulation;
    int page_count;

public:
    SelfPublishCard(const string &auth, const string &titl,
                    const string &code, const string &publ,
                    int yr, int circ, int pages);

    ~SelfPublishCard() = default;
};


#endif
