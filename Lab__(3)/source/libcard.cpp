#include "../header/libcard.h"


LibCard::LibCard(const string &auth, const string &titl, const string &code)
        : author(auth), title(titl), thematic_code(code) {

}

LibCard::~LibCard() {
}

string LibCard::get_author() const {
    return author;
}

string LibCard::get_title() const {
    return title;
}

string LibCard::get_thematic_code() const {
    return thematic_code;
}

string LibCard::get_alphabetical_search() const {
    return author + " - " + title;
}
