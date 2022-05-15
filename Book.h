#ifndef __BOOK_H
#define __BOOK_H

#include "MyString.h"

#include <iostream>
#include <cstring>
#include <fstream>

class Book
{
private:
    /// the components of a book
    MyString nameAuthor;
    MyString bookTitle;
    MyString nameTextFile;
    MyString shortDescription;
    float rating;
    MyString ISBN;

public:
    /// Constructor with parameters for Book
    Book(MyString nameAuthor, MyString bookTitle, MyString nameTextFile, MyString shortDescription, float rating, MyString ISBN);

    MyString getNameAuthor() const; /// returning name of the authot
    MyString getBookTitle() const; /// returning title of the book
    MyString getNameTextFile() const; /// returning name of the text file where the text of the book is
    MyString getShortDescription() const; /// returning the short description of the book
    float getRating() const; /// returning the rating of the book
    MyString getISBN() const; /// returning the ISBN of the book
};

#endif