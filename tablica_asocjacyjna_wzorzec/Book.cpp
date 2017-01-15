#include "Book.h"

Book::Book(const char *autor, const char *category, unsigned int pages, bool booked) :
    author(autor), category(category), pages(pages), booked(booked)
{

}

std::ostream &operator<<(std::ostream &os, const Book &book)
{
    os << "Author: " << book.author << ", category: " << book.category << ", pages: " << book.pages << ", booked: " << (book.booked ? "yes" : "no") << "\n";
    return os;
}
