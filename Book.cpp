#include "Book.h"

Book::Book(MyString nameAuthor, MyString bookTitle, MyString nameTextFile, MyString shortDescription, float rating, MyString ISBN)
{
    this->nameAuthor = nameAuthor;
    this->bookTitle = bookTitle;
    this->nameTextFile = nameTextFile;
    this->shortDescription = shortDescription;
    this->rating = rating;
    this->ISBN = ISBN;
}

MyString Book::getNameAuthor() const
{
    return nameAuthor;
}

MyString Book::getBookTitle() const
{
    return bookTitle;
}

MyString Book::getNameTextFile() const
{
    return nameTextFile;
}

MyString Book::getShortDescription() const
{
    return shortDescription;
}

float Book::getRating() const
{
    return rating;
}

MyString Book::getISBN() const
{
    return ISBN;
}
