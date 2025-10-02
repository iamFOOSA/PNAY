#include "../header/BookCard.h"
#include <string>

BookCard::BookCard(const std::string &auth, const std::string &titl,
                   const std::string &code, const std::string &publ,
                   int yr, int circ, int pages, Article *article)
        : SelfPublishCard(auth, titl, code, publ, yr, circ, pages), book_article(article) {
}

BookCard::~BookCard() {
    delete book_article;
}

BookCard::BookCard(const BookCard &other)
        : SelfPublishCard(other),
          book_article(other.book_article ? new Article(*other.book_article) : nullptr) {
}

BookCard &BookCard::operator=(const BookCard &other) {
    if (this != &other) {
        SelfPublishCard::operator=(other);
        delete book_article;
        book_article = other.book_article ? new Article(*other.book_article) : nullptr;
    }
    return *this;
}

BookCard::BookCard(BookCard&& other) noexcept
        : SelfPublishCard(other), book_article(other.book_article) {
    other.book_article = nullptr;
}

BookCard &BookCard::operator=(BookCard &&other) noexcept {
    if (this != &other) {
        SelfPublishCard::operator=(other);
        delete book_article;
        book_article = other.book_article;
        other.book_article = nullptr;
    }
    return *this;
}
