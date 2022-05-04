#ifndef USER_CONNECTION_H
#define USER_CONNECTION_H

#include "ElectronicLibrary.h"

class UserConnection
{
private:
    ElectronicLibrary MyLibrary;

    void helpChoise();


    void sortingBooks();

    void addBook();

public:
    void runProgram();

};




#endif