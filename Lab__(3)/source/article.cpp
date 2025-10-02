#include "../header/article.h"

Article::Article(const std::string &article_title, const std::string &author)
        : title(article_title), author_name(author) {
}

Article::~Article() = default;

std::string Article::get_title() const {
    return title;
}

std::string Article::get_author_name() const {
    return author_name;
}