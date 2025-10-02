#ifndef LAB___3__LIBCARD_H
#define LAB___3__LIBCARD_H

#include <string>


class LibCard {
private:
    std::string author;
    std::string title;
    std::string thematic_code;

public:
    LibCard(const std::string &auth, const std::string &titl, const std::string &code);

    ~LibCard();

    std::string get_author() const;

    std::string get_title() const;

    std::string get_thematic_code() const;

    std::string get_alphabetical_search() const;
};


#endif
