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
    std::fstream nameTextFile;
    char *shortDescription;
    float rating;
    char *ISBN;

    void copyFrom();
    void clear();

public:
    Book();
    Book(const char *nameAuthor, const char *bookTitle, std::fstream nameTextFile, const char *shortDescription, float rating, const char *ISBN);
    Book(const Book &other);
    Book &operator=(const Book &other);
    ~Book();
};

#endif