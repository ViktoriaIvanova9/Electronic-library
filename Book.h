#ifndef __BOOK_H
#define __BOOK_H

#include "MyString.h"

#include <iostream>
#include <cstring>
#include <fstream>

class Book
{
private:
    MyString nameAuthor;
    MyString bookTitle;
    MyString nameTextFile;
    MyString shortDescription;
    float rating;
    MyString ISBN;

public:
    Book(MyString nameAuthor, MyString bookTitle, MyString nameTextFile, MyString shortDescription, float rating, MyString ISBN);

    MyString getNameAuthor() const;
    MyString getBookTitle() const;
    MyString getNameTextFile() const;
    MyString getShortDescription() const;
    float getRating() const;
    MyString getISBN() const;
};

#endif