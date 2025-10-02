#include "../header/CollectionCard.h"

CollectionCard::CollectionCard(const string &auth, const string &titl,
                               const string &code, const string &publ,
                               int yr, int circ, int pages)
        : SelfPublishCard(auth, titl, code, publ, yr, circ, pages) {

}

CollectionCard::~CollectionCard() {
    for (int i = 0; i < article_count; i++) {
        delete articles[i];
    }
    delete[] articles;
}

void CollectionCard::add_article(Article *article) {
    if (article_count >= capacity) {
        int new_capacity = (capacity == 0) ? 2 : capacity * 2;
        auto **new_articles = new Article *[new_capacity];

        for (int i = 0; i < article_count; i++) {
            new_articles[i] = articles[i];
        }

        delete[] articles;
        articles = new_articles;
        capacity = new_capacity;
    }

    articles[article_count] = article;
    article_count++;
}