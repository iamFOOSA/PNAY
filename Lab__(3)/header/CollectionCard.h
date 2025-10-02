#ifndef LAB___3__COLLECTIONCARD_H
#define LAB___3__COLLECTIONCARD_H

#include "../header/SelfPublishCard.h"
#include "../header/article.h"

class CollectionCard : public SelfPublishCard {
private:
    Article **articles;
    int article_count = 0;
    int capacity = 0;

public:
    CollectionCard(const string &auth, const string &titl, const string &code,
                   const string &publ, int yr, int circ, int pages);

    ~CollectionCard();

    void add_article(Article *article);
};

#endif
