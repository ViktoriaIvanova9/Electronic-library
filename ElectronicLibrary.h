#ifndef __ELECTRONIC_LIBRARY_H
#define __ELECTRONIC_LIBRARY_H

#include "Book.h"

class ElectronicLibrary
{
private:
    Book* BooksLibrary;
    size_t currCountBooks;
    size_t capacityLibrary;

    void copyFrom();
    void clear();

    void resize();

public:
    ElectronicLibrary();
    ElectronicLibrary(const Book* BooksLibrary, size_t currCountBooks,size_t capacityLibrary);
    ElectronicLibrary(const ElectronicLibrary& other);
    ElectronicLibrary(const ElectronicLibrary& other);
    ~ElectronicLibrary();

    void sortBooksBy();
    void printSortedBooks() const;

    Book& findBook();
    void addBookToLibrary();
    void removeBookFromLibrary();

    void printBookInfo() const;
};

#endif