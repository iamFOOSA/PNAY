#include "../header/SelfPublishCard.h"


SelfPublishCard::SelfPublishCard(const std::string &auth, const std::string &titl,
                                 const std::string &code, const std::string &publ,
                                 int yr, int circ, int pages)
        : LibCard(auth, titl, code), publisher(publ), year(yr),
          circulation(circ), page_count(pages) {
}