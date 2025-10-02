#include "../header/CollectionCard.h"
#include <string>
CollectionCard::CollectionCard(const std::string &auth, const std::string &titl,
                               const std::string &code, const std::string &publ,
                               int yr, int circ, int pages)
        : SelfPublishCard(auth, titl, code, publ, yr, circ, pages){
}

CollectionCard::~CollectionCard() {
    for (int i = 0; i < article_count; i++) {
        delete articles[i];
    }
    delete[] articles;
}

void CollectionCard::add_article(Article *article) {
    if (article_count >= capacity) {
        int new_capacity = std::max(2, capacity * 2);
        if (new_capacity <= article_count) {
            new_capacity = article_count + 1;
        }

        auto new_articles = new Article *[new_capacity];

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