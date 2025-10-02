#include "../header/article.h"

Article::Article(const string &article_title, const string &author)
        : title(article_title), author_name(author) {

}

Article::~Article() = default;

string Article::get_title() const {
    return title;
}

string Article::get_author_name() const {
    return author_name;
}