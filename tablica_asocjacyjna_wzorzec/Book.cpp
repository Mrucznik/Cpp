#include "Book.h"

Book::Book(const char *autor, const char *category, unsigned int pages) :
    author(autor), category(category), pages(pages)
{

}

std::ostream &operator<<(std::ostream &os, const Book &book)
{
    os << "Author: " << book.author << ", category: " << book.category << ", pages: " << book.pages << "\n";
    return os;
}
