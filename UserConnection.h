#ifndef __USER_CONNECTION_H
#define __USER_CONNECTION_H

#include "ElectronicLibrary.h"

class UserConnection
{
private:
    ElectronicLibrary MyLibrary;
    bool validPassword();

    void chooseFunction();
    unsigned chooseOrderOfSorting();
    unsigned chooseSortingProperty();
    unsigned chooseTypeOfPrinting();
    bool deleteFile();
public:
    void runProgram();
};

#endif