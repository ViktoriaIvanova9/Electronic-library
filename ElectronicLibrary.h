#ifndef __ELECTRONIC_LIBRARY_H
#define __ELECTRONIC_LIBRARY_H

#include "Book.h"

class ElectronicLibrary
{
private:
    Book **BooksLibrary; /// using pointer to array to prevent using default constructor(empty book couldnn't exist)
    size_t currCountBooks;
    size_t capacityLibrary;

    void copyFrom(Book **BooksLibrary, size_t currCountBooks, size_t capacityLibrary); /// helper function for the constructor, copy constructor and operator=
    void clear(); /// helper function for the destructor
    void resize();

    void shift(int position); /// shifting all elements after the removed left
    bool isEmpty(); /// checking if the library has zero books

public:
    static const int BUFF_SIZE = 1024; /// constant variable for the size of the buffer for reading and writing to files
    const float EPSILON = 0.001; /// constant variable for comparing float variables in selection sort

    ElectronicLibrary(); /// default constructor for the empty library
    ElectronicLibrary(Book **BooksLibrary, size_t currCountBooks, size_t capacityLibrary); /// constructor with parameters
    ElectronicLibrary(const ElectronicLibrary &other); ///copy constructor
    ElectronicLibrary &operator=(const ElectronicLibrary &other); /// operator=
    ~ElectronicLibrary(); /// destructor

    void readFromFile(); /// reading all previous written books in the beginning of the program

    void swap(Book *first, Book *second); /// swapping two books
    void selectionSort(Book **arrOfBooks, size_t booksCount, unsigned property, bool order);
    void sortBooksBy(int property, int order); /// sorting by the chosen property
    void printSortedBooks() const; /// printing on the console serted books by the chosen property

    void printInfoAboutFoundBook(size_t position) const; 
    /// finding book by exact match between title, author and ISBN or by part of short description
    void findBook(MyString nameBook, MyString bookAuthor, MyString shortDescription, MyString ISBN, bool property); 

    void addBookToTextFile(const MyString nameTextFile, const MyString bookContent); /// creating the file of the book and writing its text in the file
    /// adding book to the array of books
    void addBookToLibrary(MyString nameAuthor, MyString bookTitle, MyString nameTextFile, MyString shortDescription, float rating, MyString ISBN);

    void removeBookFromLibrary(MyString ISBN); /// removing the chosen book from the array
    MyString getBookTextFile(MyString ISBN); /// finding the book's text file by given ISBN
    void deleteFileBook(MyString nameTextFile); /// deleting the file of the book which is removed from the library(array)

    size_t getLinesCount(const MyString fileName); /// counting the lines of a text file
    void printBookPages(const MyString fileName, size_t numberPages); /// printing N lines of the chosen text file
    void printBookSentences(const MyString fileName, size_t numberSentences) const; /// printing N sentences lines of the chosen text file

    void writeToFile() const; /// when the library is exiting writing all new added books to the text file "BooksLibrayr.txt"
};

#endif