#ifndef TABLICA_ASOCJACYJNA_WZORZEC_BOOK_H
#define TABLICA_ASOCJACYJNA_WZORZEC_BOOK_H

#include <ostream>

class Book
{
public:
    const char* author;
    const char* category;
    unsigned int pages;
    bool booked;

    friend std::ostream &operator<<(std::ostream &os, const Book &book);

    Book(const char* autor, const char* category, unsigned int pages, bool booked);
};


#endif //TABLICA_ASOCJACYJNA_WZORZEC_BOOK_H
