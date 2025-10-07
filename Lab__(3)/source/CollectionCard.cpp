#include "../header/CollectionCard.h"
#include <string>
CollectionCard::CollectionCard(const std::string &auth, const std::string &titl,
                               const std::string &code, const std::string &publ,
                               int year, int circulation, int page_count)
        : SelfPublishCard(auth, titl, code, publ, year, circulation, page_count) {
}

CollectionCard::~CollectionCard() {
    for (int i = 0; i < article_count; i++) {
        delete articles[i];
    }
    delete[] articles;
}

CollectionCard::CollectionCard(CollectionCard&& other) noexcept
        : SelfPublishCard(other),
          articles(other.articles),
          article_count(other.article_count),
          capacity(other.capacity) {
    other.articles = nullptr;
    other.article_count = 0;
    other.capacity = 0;
}

CollectionCard& CollectionCard::operator=(CollectionCard&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < article_count; i++) {
            delete articles[i];
        }
        delete[] articles;

        SelfPublishCard::operator=(other);

        articles = other.articles;
        article_count = other.article_count;
        capacity = other.capacity;

        other.articles = nullptr;
        other.article_count = 0;
        other.capacity = 0;
    }
    return *this;
}

void CollectionCard::add_article(Article *article) {
    if (article_count >= capacity) {
        int new_capacity = (capacity == 0) ? 2 : capacity * 2;

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