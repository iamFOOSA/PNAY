#include "../header/BookCard.h"
#include <string>

BookCard::~BookCard() {
    delete book_article;
}



BookCard &BookCard::operator=(const BookCard &other) {
    if (this != &other) {
        SelfPublishCard::operator=(other);
        delete book_article;
        book_article = other.book_article ? new Article(*other.book_article) : nullptr;
    }
    return *this;
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