#include "UserConnection.h"

bool UserConnection::validPassword()
{
    MyString realPassword("0346012190");
    MyString userPassword;
    std::cout << "PASSWORD: ";
    std::cin >> userPassword;

    return realPassword == userPassword;
}

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
    int sortingOrder;

    std::cout << "To sort in ascending order press 1\n";
    std::cout << "To sort in descending order press 2\n";

    while (true)
    {
        std::cin >> sortingOrder;
        if (sortingOrder == 1 || sortingOrder == 2)
            break;
        else
            std::cout << "Enter valid number!\n";
    }
    return sortingOrder;
}

unsigned UserConnection::chooseSortingProperty()
{
    unsigned sortingProperty;

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
    return sortingProperty;
}

unsigned UserConnection::chooseTypeOfPrinting()
{
    unsigned typeOfPrinting;

    std::cout << "To print by pages press 1\n";
    std::cout << "To print by sentences press 2\n";

    while (true)
    {
        std::cin >> typeOfPrinting;
        if (typeOfPrinting == 1 || typeOfPrinting == 2)
            break;
        else
            std::cout << "Enter valid number!\n";
    }
    return typeOfPrinting;
}

bool UserConnection::deleteFile()
{
    unsigned chooseDeleting;

    std::cout << "To delete file of the book press 1\n";
    std::cout << "To save the file of the book press 0\n";

    while (true)
    {
        std::cin >> chooseDeleting;
        if (chooseDeleting == 1 || chooseDeleting == 0)
            break;
        else
            std::cout << "Enter a valid number!\n";
    }
    return chooseDeleting;
}

void UserConnection::runProgram()
{
    try
    {
        this->MyLibrary.readFromFile();
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
                        this->MyLibrary.sortBooksBy(1, 1); // ascending, by title

                    if (sortingProperty == 2)
                        this->MyLibrary.sortBooksBy(2, 1); // ascending, by author

                    if (sortingProperty == 3)
                        this->MyLibrary.sortBooksBy(3, 1); // ascending, by rating
                }

                else
                {
                    sortingProperty = chooseSortingProperty();

                    if (sortingProperty == 1)
                        this->MyLibrary.sortBooksBy(1, 2); // descending, by title

                    if (sortingProperty == 2)
                        this->MyLibrary.sortBooksBy(2, 2); // descending, by author

                    if (sortingProperty == 3)
                        this->MyLibrary.sortBooksBy(3, 2); // descending, by rating
                }
            }

            else if (selectOption == 2)
            {
                MyString nameAuthor, bookTitle, shortDescription, ISBN;

                std::cout << "Author of the book: ";
                std::cin >> nameAuthor;

                std::cout << "Name of the book: ";
                std::cin >> bookTitle;

                std::cout << "Description of the book: ";
                std::cin >> shortDescription;

                std::cout << "Book ISBN: ";
                std::cin >> ISBN;

                std::cout << std::endl;

                this->MyLibrary.findBook(bookTitle, nameAuthor, shortDescription, ISBN);
            }

            else if (selectOption == 3)
            {
                if (validPassword())
                {
                    MyString nameAuthor, bookTitle, nameTextFile, shortDescription, ISBN, bookContent;

                    std::cout << "Author of the book: ";
                    std::cin >> nameAuthor;

                    std::cout << "Name of the book: ";
                    std::cin >> bookTitle;

                    std::cout << "Name of the book's text file: ";
                    std::cin >> nameTextFile;

                    std::cout << "Description of the book: ";
                    std::cin >> shortDescription;

                    float rating;
                    std::cout << "Book rating: ";
                    std::cin >> rating;

                    std::cout << "Book ISBN: ";
                    std::cin >> ISBN;

                    std::cout << "Here write the content of the book: ";
                    std::cin >> bookContent;

                    this->MyLibrary.addBookToLibrary(nameAuthor, bookTitle, nameTextFile, shortDescription, rating, ISBN);
                    // this->MyLibrary.addBookToMainTextFile(nameAuthor, bookTitle, nameTextFile, shortDescription, rating, ISBN);
                    this->MyLibrary.addBookToBookTextFile(nameTextFile, bookContent);
                }
                else
                {
                    std::cout << "INVALID PASSWORD!\n";
                }
            }

            else if (selectOption == 4)
            {
                if (validPassword())
                {
                    MyString ISBN;
                    std::cout << "Write the ISBN of the book you want to remove: ";
                    std::cin >> ISBN;

                    MyString nameFile = this->MyLibrary.getBookTextFile(ISBN);
                    this->MyLibrary.removeBookFromLibrary(ISBN);

                    if (deleteFile())
                    {
                        this->MyLibrary.deleteFileBook(nameFile);
                    }
                }
                else
                {
                    std::cout << "INVALID PASSWORD!\n";
                }
            }

            else if (selectOption == 5)
            {
                unsigned typeOfPrinting;

                MyString nameTextFile;
                std::cout << "Write the name of the text file you want to read from: ";
                std::cin >> nameTextFile;

                typeOfPrinting = chooseTypeOfPrinting();

                if (typeOfPrinting == 1)
                {
                    size_t countLines;
                    std::cout << "How many pages do you want to be printed on the console? ";
                    std::cin >> countLines;

                    if (countLines > MyLibrary.getLinesCount(nameTextFile))
                    {
                        std::cout << "There aren't so much pages in this book!\n";
                        std::cout << std::endl;
                        return;
                    }

                    this->MyLibrary.printBookPages(nameTextFile, countLines);
                }

                else
                {
                    size_t countSentences;
                    std::cout << "How many sentences do you want to be printed on the console? ";
                    std::cin >> countSentences;

                    this->MyLibrary.printBookSentences(nameTextFile, countSentences);
                }
            }

            else if (selectOption == 0)
            {
                this->MyLibrary.writeToFile();
                return;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
}