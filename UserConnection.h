#ifndef __USER_CONNECTION_H
#define __USER_CONNECTION_H

#include <conio.h> /// using getch()

#include "ElectronicLibrary.h"

class UserConnection
{
private:
    static const int BUFF_SIZE = 1024; /// constant variable for the capacity of the buffer when read and write to file

    ElectronicLibrary MyLibrary; /// creating my library 

    bool validPassword(); /// Checking if the password entered by the user for adding or removing a book is the same as the real password

    void chooseFunction(); /// pressing number between 0 and 5 to choose the function to be performed
    unsigned chooseOrderOfSorting(); /// Choose sorting in ascending or descending order
    unsigned chooseSortingProperty(); /// Choose how to sort: by author, title ot rating
    unsigned chooseTypeOfPrinting(); /// Choose to print N sentences or N lines(pages)
    bool deleteFile(); /// Choose whether to delete the file with the text of the book you removed
    bool findBookBy(); /// Choose to find book by name, title and ISBN or by part of the short description

public:
    void runProgram();
};

#endif