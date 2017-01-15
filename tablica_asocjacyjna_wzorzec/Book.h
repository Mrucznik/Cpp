#ifndef TABLICA_ASOCJACYJNA_WZORZEC_BOOK_H
#define TABLICA_ASOCJACYJNA_WZORZEC_BOOK_H

#include <ostream>

class Book
{
    const char* author;
    const char* category;
    unsigned int pages;

    Book(const char* autor, const char* category, unsigned int pages);

    friend std::ostream &operator<<(std::ostream &os, const Book &book);
};


#endif //TABLICA_ASOCJACYJNA_WZORZEC_BOOK_H
