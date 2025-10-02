#ifndef LAB___3__ARTICLE_H
#define LAB___3__ARTICLE_H

#include <string>

using namespace std;

class Article {
private:
    string title;
    string author_name;

public:
    Article(const string &article_title, const string &author);

    ~Article();

    string get_title() const;

    string get_author_name() const;
};

#endif
