#ifndef __USER_CONNECTION_H
#define __USER_CONNECTION_H

#include "ElectronicLibrary.h"

class UserConnection
{
private:
    ElectronicLibrary MyLibrary;

    void chooseFunction();

    unsigned chooseOrderOfSorting();
    unsigned chooseSortingProperty();

    void addBook();
    void removeBook();
public:
    void runProgram();
};




#endif