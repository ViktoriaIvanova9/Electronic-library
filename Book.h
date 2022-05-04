#ifndef __BOOK_H
#define __BOOK_H

#include <iostream>
#include <cstring>
#include <fstream>

class Book
{
private:
    char *nameAuthor;
    char *bookTitle;
    char *nameTextFile;
    char *shortDescription;
    float rating;
    char *ISBN;

    void copyFrom(const char *nameAuthor, const char *bookTitle, const char *nameTextFile, const char *shortDescription, float rating, const char *ISBN);
    void clear();

public:
    Book(const char *nameAuthor, const char *bookTitle, const char *nameTextFile, const char *shortDescription, float rating, const char *ISBN);
    Book(const Book &other);
    Book &operator=(const Book &other);
    ~Book();

    const char *getNameAuthor() const;
    const char *getBookTitle() const;
    const char *getNameTextFile() const;
    const char *getShortDescription() const;
    float getRating() const;
    const char *getISBN() const;
};

#endif