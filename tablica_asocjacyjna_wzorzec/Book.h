#ifndef TABLICA_ASOCJACYJNA_WZORZEC_BOOK_H
#define TABLICA_ASOCJACYJNA_WZORZEC_BOOK_H

#include <ostream>

class Book
{
public:
    const char* author;
    const char* category;
    unsigned int pages;

    friend std::ostream &operator<<(std::ostream &os, const Book &book);

    Book(const char* autor, const char* category, unsigned int pages);
};


#endif //TABLICA_ASOCJACYJNA_WZORZEC_BOOK_H
