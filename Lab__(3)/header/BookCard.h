#ifndef LAB___3__BOOKCARD_H
#define LAB___3__BOOKCARD_H

#include "../header/CollectionCard.h"
#include "../header/article.h"

class BookCard : public SelfPublishCard {
private:
    Article *book_article;

public:
    BookCard(const string &auth, const string &titl,
             const string &code, const string &publ,
             int yr, int circ, int pages, Article *article);

    ~BookCard();

    BookCard(const BookCard &other);

    BookCard &operator=(const BookCard &other);

    BookCard(BookCard &&other) noexcept;

    BookCard &operator=(BookCard &&other) noexcept;
};

#endif
