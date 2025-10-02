#ifndef LAB___3__BOOKCARD_H
#define LAB___3__BOOKCARD_H

#include "../header/CollectionCard.h"
#include "../header/article.h"
#include <string>

struct BookData {
    std::string author;
    std::string title;
    std::string code;
    std::string publisher;
    int year;
    int circulation;
    int pages;
};

class BookCard : public SelfPublishCard {
private:
    Article *book_article;

public:
    BookCard(const BookData &data, Article *article)
            : SelfPublishCard(data.author, data.title, data.code,
                              data.publisher, data.year, data.circulation, data.pages),
              book_article(article) {}

    ~BookCard();

    BookCard(const BookCard &other);

    BookCard &operator=(const BookCard &other);

    BookCard(BookCard &&other) noexcept;

    BookCard &operator=(BookCard &&other) noexcept;
};

#endif
