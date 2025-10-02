#ifndef LAB___3__ARTICLE_H
#define LAB___3__ARTICLE_H

#include <string>


class Article {
private:
    std::string title;
    std::string author_name;

public:
    Article(const std::string &article_title, const std::string &author);

    ~Article();

    std::string get_title() const;

    std::string get_author_name() const;
};

#endif
