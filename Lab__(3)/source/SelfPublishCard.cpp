#include "../header/SelfPublishCard.h"


SelfPublishCard::SelfPublishCard(const std::string &auth, const std::string &titl,
                                 const std::string &code, const std::string &publ,
                                 int year, int circulation, int page_count)
        : LibCard(auth, titl, code), publisher(publ), year(year),
          circulation(circulation), page_count(page_count) {
}
