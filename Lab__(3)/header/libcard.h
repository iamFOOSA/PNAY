#ifndef LAB___3__LIBCARD_H
#define LAB___3__LIBCARD_H

#include <string>

using namespace std;

class LibCard {
protected:
    string author;
    string title;
    string thematic_code;

public:
    LibCard(const string &auth, const string &titl, const string &code);

    ~LibCard();

    string get_author() const;

    string get_title() const;

    string get_thematic_code() const;

    string get_alphabetical_search() const;
};


#endif
