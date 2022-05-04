#include "Book.h"

void Book::copyFrom(const char *nameAuthor, const char *bookTitle, const char *nameTextFile, const char *shortDescription, float rating, const char *ISBN)
{
    this->nameAuthor = new char[strlen(nameAuthor) + 1];
    strcpy(this->nameAuthor, nameAuthor);

    this->bookTitle = new char[strlen(bookTitle) + 1];
    strcpy(this->bookTitle, bookTitle);

    this->nameTextFile = new char[strlen(nameTextFile) + 1];
    strcpy(this->nameTextFile, nameTextFile);

    this->shortDescription = new char[strlen(shortDescription) + 1];
    strcpy(this->shortDescription, shortDescription);

    this->rating = rating;

    this->ISBN = new char[strlen(ISBN) + 1];
    strcpy(this->ISBN, ISBN);
}

void Book::clear()
{
    delete[] nameAuthor;
    nameAuthor = nullptr;

    delete[] bookTitle;
    bookTitle = nullptr;

    delete[] nameTextFile;
    nameTextFile = nullptr;

    delete[] shortDescription;
    shortDescription = nullptr;

    delete[] ISBN;
    ISBN = nullptr;
}

Book::Book(const char *nameAuthor, const char *bookTitle, const char *nameTextFile, const char *shortDescription, float rating, const char *ISBN)
{
    copyFrom(nameAuthor, bookTitle, nameTextFile, shortDescription, rating, ISBN);
}

Book::Book(const Book &other)
{
    copyFrom(other.nameAuthor, other.bookTitle, other.nameTextFile, other.shortDescription, other.rating, other.ISBN);
}

Book &Book::operator=(const Book &other)
{
    if (this != &other)
    {
        clear();
        copyFrom(other.nameAuthor, other.bookTitle, other.nameTextFile, other.shortDescription, other.rating, other.ISBN);
    }
    return *this;
}

Book::~Book()
{
    clear();
}

const char *Book::getNameAuthor() const
{
    return nameAuthor;
}

const char *Book::getBookTitle() const
{
    return bookTitle;
}

const char *Book::getNameTextFile() const
{
    return nameTextFile;
}

const char *Book::getShortDescription() const
{
    return shortDescription;
}

float Book::getRating() const
{
    return rating;
}

const char *Book::getISBN() const
{
    return ISBN;
}