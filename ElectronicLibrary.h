#ifndef __ELECTRONIC_LIBRARY_H
#define __ELECTRONIC_LIBRARY_H

#include "Book.h"

const size_t DEFAULT_COUNT_BOOKS = 10;

class ElectronicLibrary
{
private:
    Book **BooksLibrary;
    size_t currCountBooks;
    size_t capacityLibrary;

    void copyFrom(Book **BooksLibrary, size_t currCountBooks, size_t capacityLibrary);
    void clear();

    void resize();
    void shift(int position);

    bool isEmptyArr();

    void addBookToTextFile(MyString nameAuthor, MyString bookTitle, const MyString nameTextFile, MyString shortDescription, float rating, MyString ISBN) const;

public:
    ElectronicLibrary();
    ElectronicLibrary(Book **BooksLibrary, size_t currCountBooks, size_t capacityLibrary);
    ElectronicLibrary(const ElectronicLibrary &other);
    ElectronicLibrary &operator=(const ElectronicLibrary &other);
    ~ElectronicLibrary();

    void swap(Book *first, Book *second);
    void selectionSort(Book **arrOfBooks, size_t booksCount, unsigned property, bool order);

    void sortBooksBy(int property, int order);
    void printSortedBooks() const;

    void findBook(MyString nameBook, MyString bookAuthor, MyString ISBN, MyString shortDescription);

    void addBookToLibrary(MyString nameAuthor, MyString bookTitle, MyString nameTextFile, MyString shortDescription, float rating, MyString ISBN);

    void removeBookFromLibrary(MyString ISBN);
    void removeBookFromTextFile(MyString ISBN, const MyString nameTextFile);

    void printBookInfo() const;
};

#endif