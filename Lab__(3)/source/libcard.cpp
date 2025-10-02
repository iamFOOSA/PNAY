#include "../header/libcard.h"


LibCard::LibCard(const std::string &auth, const std::string &titl, const std::string &code)
        : author(auth), title(titl), thematic_code(code) {
}

LibCard::~LibCard() = default;

std::string LibCard::get_author() const {
    return author;
}

std::string LibCard::get_title() const {
    return title;
}

std::string LibCard::get_thematic_code() const {
    return thematic_code;
}

std::string LibCard::get_alphabetical_search() const {
    return author + " - " + title;
}