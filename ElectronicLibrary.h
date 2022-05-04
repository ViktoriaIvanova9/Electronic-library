#ifndef __ELECTRONIC_LIBRARY_H
#define __ELECTRONIC_LIBRARY_H

#include "Book.h"

const size_t DEFAULT_COUNT_BOOKS=10;

class ElectronicLibrary
{
private:
    Book **BooksLibrary;
    size_t currCountBooks;
    size_t capacityLibrary;

    void copyFrom(const Book **BooksLibrary, size_t currCountBooks, size_t capacityLibrary);
    void clear();

    void resize();
    void shift(int position);

    bool isEmptyArr();

    void addBookToTextFile(const Book& obj);
public:
    ElectronicLibrary();
    ElectronicLibrary(const Book **BooksLibrary, size_t currCountBooks, size_t capacityLibrary);
    ElectronicLibrary(const ElectronicLibrary &other);
    ElectronicLibrary &operator=(const ElectronicLibrary &other);
    ~ElectronicLibrary();

    void startRunning();

    void sortBooksBy(int order, int criteria);
    void printSortedBooks() const;

    Book &findBook();

    void addBookToLibrary(const Book& obj);
    void removeBookFromLibrary(const Book& obj);

    void printBookInfo() const;
};

#endif