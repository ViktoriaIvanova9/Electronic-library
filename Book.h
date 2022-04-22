#ifndef __BOOK_H
#define __BOOK_H

class Book
{
private:
    char* nameAuthor;
    char* bookTitle;
    char* nameTextFile;
    char* shortDescription;
    float rating;
    char* ISBN;

    void copyFrom();
    void clear();
public:
    Book();
    Book(const Book& other);
    Book& operator=(const Book& other);
    ~Book();
};

#endif