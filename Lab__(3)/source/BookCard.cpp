#include "../header/BookCard.h"

BookCard::BookCard(const string &auth, const string &titl,
                   const string &code, const string &publ,
                   int yr, int circ, int pages, Article *article)
        : SelfPublishCard(auth, titl, code, publ, yr, circ, pages), book_article(article) {}

BookCard::~BookCard() {
    delete book_article;
}
