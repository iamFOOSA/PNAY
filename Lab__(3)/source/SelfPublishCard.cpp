#include "../header/SelfPublishCard.h"


SelfPublishCard::SelfPublishCard(const string &auth, const string &titl,
                                 const string &code, const string &publ,
                                 int yr, int circ, int pages)
        : LibCard(auth, titl, code), publisher(publ), year(yr),
          circulation(circ), page_count(pages) {}

SelfPublishCard::~SelfPublishCard() {
}