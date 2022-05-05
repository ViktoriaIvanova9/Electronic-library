#include "UserConnection.h"

void UserConnection::chooseFunction()
{
    std::cout << "For sorting all books choose 1\n";
    std::cout << "For finding a book choose 2\n";
    std::cout << "For adding new book choose 3\n";
    std::cout << "For removing any book choose 4\n";
    std::cout << "For printing any book choose 5\n";

    std::cout << "For exiting library choose 0\n";
}

unsigned UserConnection::chooseOrderOfSorting()
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
}

unsigned UserConnection::chooseSortingProperty()
{
    int sortingProperty;

    std::cout << "To sort by title press 1\n";
    std::cout << "To sort by author press 2\n";
    std::cout << "To sort by rating press 3\n";

    while (true)
    {
        std::cin >> sortingProperty;
        if (sortingProperty == 1 || sortingProperty == 2 || sortingProperty == 3)
            break;
        else
            std::cout << "Enter valid number!\n";
    }
}

void UserConnection::addBook()
{
    MyString nameAuthor;
    std::cout << "Author of the book: ";
    std::cin>>nameAuthor;

    MyString bookTitle;
    std::cout << "Name of the book: ";
    std::cin>>bookTitle;
    std::cout << "Name of the book's text file: ";
    std::cout << "Desctiption of the book: ";
    std::cout << "Book rating: ";
    std::cout << "Book ISBN: ";
}

void UserConnection::runProgram()
{
    unsigned selectOption, orderOfSorting, sortingProperty;

    while (true)
    {
        chooseFunction();
        std::cin >> selectOption;

        if (selectOption == 1)
        {
            orderOfSorting = chooseOrderOfSorting();

            if (orderOfSorting == 1)
            {
                sortingProperty = chooseSortingProperty();

                if (sortingProperty == 1)
                    this->MyLibrary.sortBooksBy(1, 1); //ascending, by title

                if (sortingProperty == 2)
                    this->MyLibrary.sortBooksBy(1, 2); //ascending, by author

                if (sortingProperty == 3)
                    this->MyLibrary.sortBooksBy(1, 3); //ascending, by rating
            }

            else
            {
                chooseSortingProperty();
                std::cin >> sortingProperty;

                if (sortingProperty == 1)
                    this->MyLibrary.sortBooksBy(2, 1); //descending, by title                               

                if (sortingProperty == 2)               
                    this->MyLibrary.sortBooksBy(2, 2); //descending, by author                      

                if (sortingProperty == 3)               
                    this->MyLibrary.sortBooksBy(2, 3); //descending, by rating                      
            }
        }

        else if (selectOption == 2)
        {
        }

        else if (selectOption == 3)
        {
        }

        else if (selectOption == 4)
        {
        }

        else if (selectOption == 5)
        {
        }

        else if (selectOption == 0)
        {
            std::cout << "For saving changes press 'true'.\n";
            std::cout << "For NOT saving changes press 'false'.\n";

            std::cout << "Do you want to save the changes? ";

            bool saveChanges;
            std::cin >> saveChanges;

            if (saveChanges == true)
            {
                // promeni vuv faila
            }

            else
            {
                // nishto??
            }

            return;
        }
    }
}