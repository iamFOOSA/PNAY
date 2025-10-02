#ifndef LAB___3__BOOKCARD_H
#define LAB___3__BOOKCARD_H

#include "../header/CollectionCard.h"
#include "../header/article.h"
#include <string>

class BookCard : public SelfPublishCard {
private:
    Article *book_article;

public:
    BookCard(const std::string &auth, const std::string &titl,
             const std::string &code, const std::string &publ,
             int yr, int circ, int pages, Article *article);

    ~BookCard();

    BookCard(const BookCard &other);

    BookCard &operator=(const BookCard &other);

    BookCard(BookCard &&other) noexcept;

    BookCard &operator=(BookCard &&other) noexcept;
};

#endif
