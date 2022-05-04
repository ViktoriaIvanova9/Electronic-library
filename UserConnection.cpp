#include "UserConnection.h"

void UserConnection::helpChoise()
{
    std::cout << "For sorting all books choose 1\n";
    std::cout << "For finding a book choose 2\n";
    std::cout << "For adding new book choose 3\n";
    std::cout << "For removing any book choose 4\n";
    std::cout << "For printing any book choose 5\n";

    std::cout << "For exiting library choose 0\n";
}

void UserConnection::sortingBooks()
{
    int chooseOrder;

    std::cout << "To sort in ascending order press 1\n";
    std::cout << "To sort in descending order press 2\n";

    while (true)
    {
        std::cin >> chooseOrder;
        if (chooseOrder == 1 || chooseOrder == 2)
            break;
        else
            std::cout << "Enter valid number!\n";
    }

    int chooseSortingCriteria;

    std::cout << "To sort by title press 1\n";
    std::cout << "To sort by author press 2\n";
    std::cout << "To sort by rating press 3\n";

    while (true)
    {
        std::cin >> chooseSortingCriteria;
        if (chooseSortingCriteria == 1 || chooseSortingCriteria == 2 || chooseSortingCriteria == 3)
            break;
        else
            std::cout << "Enter valid number!\n";
    }
}

void UserConnection::addBook()
{
    std::cout<<"Author of the book: ";
    char* nameAuthor=new char[]
    std::cout<<"Name of the book: ";
    std::cout<<"Name of the book's text file: ";
    std::cout<<"Desctiption of the book: ";
    std::cout<<"Book rating: ";
    std::cout<<"Book ISBN: ";
}

void UserConnection::runProgram()
{
    int selectOption;

    while (true)
    {
        helpChoise();
        std::cin >> selectOption;

        if (selectOption == 1)
        {
            if (sortingBooks() == 1)
        }
    }
}