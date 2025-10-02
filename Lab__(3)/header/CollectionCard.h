#ifndef LAB___3__COLLECTIONCARD_H
#define LAB___3__COLLECTIONCARD_H

#include "../header/SelfPublishCard.h"
#include "../header/article.h"
#include <string>

class CollectionCard : public SelfPublishCard {
private:
    Article **articles = nullptr;
    int article_count = 0;
    int capacity = 0;

public:
    CollectionCard(const std::string &auth, const std::string &titl, const std::string &code,
                   const std::string &publ, int yr, int circ, int pages);

    ~CollectionCard();

    void add_article(Article *article);
};

#endif
