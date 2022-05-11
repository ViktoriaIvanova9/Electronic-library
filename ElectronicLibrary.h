#ifndef __ELECTRONIC_LIBRARY_H
#define __ELECTRONIC_LIBRARY_H

#include "Book.h"

const size_t DEFAULT_COUNT_BOOKS = 1;

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

    bool isEmpty();

public:

    static const int BUFF_SIZE = 1024;
    const float EPSILON=0.001;
    ElectronicLibrary();
    ElectronicLibrary(Book **BooksLibrary, size_t currCountBooks, size_t capacityLibrary);
    ElectronicLibrary(const ElectronicLibrary &other);
    ElectronicLibrary &operator=(const ElectronicLibrary &other);
    ~ElectronicLibrary();

    void readFromFile();

    void swap(Book *first, Book *second);
    void selectionSort(Book **arrOfBooks, size_t booksCount, unsigned property, bool order);
    void sortBooksBy(int property, int order);
    void printSortedBooks() const;

    void findBook(MyString nameBook, MyString bookAuthor, MyString shortDescription, MyString ISBN);

    void addBookToBookTextFile(const MyString nameTextFile, const MyString bookContent);
    void addBookToLibrary(MyString nameAuthor, MyString bookTitle, MyString nameTextFile, MyString shortDescription, float rating, MyString ISBN);

    void removeBookFromLibrary(MyString ISBN);
    MyString getBookTextFile(MyString ISBN);
    void deleteFileBook(MyString nameTextFile);

    size_t getLinesCount(const MyString fileName);
    void printBookPages(const MyString fileName, size_t numberPages);
    void printBookSentences(const MyString fileName, size_t numberSentences) const;

    void writeToFile() const;
};

#endif