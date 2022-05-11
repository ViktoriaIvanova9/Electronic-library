#include "ElectronicLibrary.h"

void ElectronicLibrary::copyFrom(Book **BooksLibrary, size_t currCountBooks, size_t capacityLibrary)
{
    this->currCountBooks = currCountBooks;
    this->capacityLibrary = capacityLibrary;

    BooksLibrary = new Book *[capacityLibrary];

    for (size_t i = 0; i < currCountBooks; ++i)
    {
        this->BooksLibrary[i] = new Book(*BooksLibrary[i]);
    }
}

void ElectronicLibrary::clear()
{
    for (size_t i = 0; i < currCountBooks; ++i)
    {
        delete BooksLibrary[i];
    }

    delete[] BooksLibrary;
}

void ElectronicLibrary::resize()
{
    Book **resizedLibrary = new Book *[capacityLibrary * 2];

    for (size_t i = 0; i < capacityLibrary; ++i)
    {
        resizedLibrary[i] = BooksLibrary[i];
    }
    capacityLibrary *= 2;

    delete[] BooksLibrary;
    BooksLibrary = resizedLibrary;
}

void ElectronicLibrary::shift(int position)
{
    for (size_t i = position; i < currCountBooks - 1; ++i)
    {
        BooksLibrary[i] = BooksLibrary[i + 1];
    }
    currCountBooks--;
}

bool ElectronicLibrary::isEmpty()
{
    return currCountBooks == 0;
}

ElectronicLibrary::ElectronicLibrary()
{
    BooksLibrary = nullptr;
    currCountBooks = 0;
    capacityLibrary = 1;
}

ElectronicLibrary::ElectronicLibrary(Book **BooksLibrary, size_t currCountBooks, size_t capacityLibrary)
{
    copyFrom(BooksLibrary, currCountBooks, capacityLibrary);
}

ElectronicLibrary::ElectronicLibrary(const ElectronicLibrary &other)
{
    copyFrom(other.BooksLibrary, other.currCountBooks, other.capacityLibrary);
}

ElectronicLibrary &ElectronicLibrary::operator=(const ElectronicLibrary &other)
{
    if (this != &other)
    {
        clear();
        copyFrom(other.BooksLibrary, other.currCountBooks, other.capacityLibrary);
    }
    return *this;
}

ElectronicLibrary::~ElectronicLibrary()
{
    clear();
}

void ElectronicLibrary::readFromFile()
{
    std::ifstream fileBooks;
    fileBooks.open("BooksLibrary.txt", std::ios::in);

    if (fileBooks.fail())
    {
        std::cout << "Error while opening file!\n";
        return;
    }

    char buffer[BUFF_SIZE];
    fileBooks >> buffer;

    MyString author, name, nameTextFile, shortDescrirtion, ISBN;
    float rating;

    int size = std::atoi(buffer);
    if (size == 0)
    {
        std::cout << "The aren't any books in this library\n";
        std::cout << std::endl;
        return;
    }
    this->BooksLibrary = new Book *[size];
    this->capacityLibrary = size;

    while (fileBooks >> author >> name >> nameTextFile >> shortDescrirtion >> rating >> ISBN)
    {
        this->BooksLibrary[currCountBooks] = new Book(author, name, nameTextFile, shortDescrirtion, rating, ISBN);
        currCountBooks++;
    }

    fileBooks.close();

    if (currCountBooks != capacityLibrary)
    {
        throw std::invalid_argument("Invalid data in file.");
    }
}

void ElectronicLibrary::swap(Book *first, Book *second)
{
    Book temp = *first;
    *first = *second;
    *second = temp;
}

void ElectronicLibrary::selectionSort(Book **arrOfBooks, size_t booksCount, unsigned property, bool order)
{
    size_t i, j, minIndex;
    for (i = 0; i < booksCount - 1; ++i)
    {
        minIndex = i;

        for (j = i + 1; j < booksCount; ++j)
        {
            if (property == 1) // by title
            {
                if (order == false)
                {
                    if (arrOfBooks[minIndex]->getBookTitle() < arrOfBooks[j]->getBookTitle()) // descending order
                        minIndex = j;
                }
                else
                {
                    if (arrOfBooks[j]->getBookTitle() < arrOfBooks[minIndex]->getBookTitle()) // ascending order
                        minIndex = j;
                }
            }

            else if (property == 2) // by author
            {
                if (order == false)
                {
                    if (arrOfBooks[minIndex]->getNameAuthor() < arrOfBooks[j]->getNameAuthor()) // descending order
                        minIndex = j;
                }
                else
                {
                    if (arrOfBooks[j]->getNameAuthor() < arrOfBooks[minIndex]->getNameAuthor()) // ascending order
                        minIndex = j;
                }
            }

            else if (property == 3) // by rating
            {
                if (order == false)
                {
                    if ((arrOfBooks[minIndex]->getRating() - arrOfBooks[j]->getRating()) < EPSILON) // descending order
                        minIndex = j;
                }
                else
                {
                    if ((arrOfBooks[j]->getRating() - arrOfBooks[minIndex]->getRating()) < EPSILON) // ascending order
                        minIndex = j;
                }
            }
        }

        swap(arrOfBooks[minIndex], arrOfBooks[i]);
    }

    printSortedBooks();
}

void ElectronicLibrary::sortBooksBy(int property, int order)
{
    if (isEmpty())
    {
        std::cout << "There aren't any books in this library.\n";
        return;
    }

    if (order == 1) // ascending order sort
    {
        if (property == 1) // by title
        {
            selectionSort(BooksLibrary, currCountBooks, 1, true);
        }
        else if (property == 2) // by author
        {
            selectionSort(BooksLibrary, currCountBooks, 2, true);
        }
        else // by rating
        {
            selectionSort(BooksLibrary, currCountBooks, 3, true);
        }
    }

    else if (order == 2) // descending order sort
    {
        if (property == 1) // by title
        {
            selectionSort(BooksLibrary, currCountBooks, 1, false);
        }
        else if (property == 2) // by author
        {
            selectionSort(BooksLibrary, currCountBooks, 2, false);
        }
        else // by rating
        {
            selectionSort(BooksLibrary, currCountBooks, 3, false);
        }
    }
}

void ElectronicLibrary::printSortedBooks() const
{
    for (size_t i = 0; i < currCountBooks; ++i)
    {
        std::cout << "Title: " << BooksLibrary[i]->getBookTitle() << " Author: " << BooksLibrary[i]->getNameAuthor() << " ISBN: " << BooksLibrary[i]->getISBN() << std::endl;
    }
}

void ElectronicLibrary::findBook(MyString bookTitle, MyString bookAuthor, MyString shortDescription, MyString ISBN)
{
    for (size_t i = 0; i < currCountBooks; ++i)
    {
        if ((BooksLibrary[i]->getBookTitle() == bookTitle && BooksLibrary[i]->getNameAuthor() == bookAuthor && BooksLibrary[i]->getISBN() == ISBN) /*|| (" " + isSubstring(BooksLibrary[i]->getShortDescription(), shortDescription))*/)
        {
            std::cout << "The name of the book is: " << BooksLibrary[i]->getBookTitle() << std::endl;
            std::cout << "The author of the book is: " << BooksLibrary[i]->getNameAuthor() << std::endl;
            std::cout << "The name of text file where the book is: " << BooksLibrary[i]->getNameTextFile() << std::endl;
            std::cout << "The short description of the book is: " << BooksLibrary[i]->getShortDescription() << std::endl;
            std::cout << "The reting of the book is: " << BooksLibrary[i]->getRating() << std::endl;
            std::cout << "The ISBN of the book is: " << BooksLibrary[i]->getISBN() << std::endl;
            std::cout << std::endl;
            return;
        }
    }
    std::cout << "There isn't such book in the library!\n";
    std::cout << std::endl;
}

void ElectronicLibrary::addBookToBookTextFile(const MyString nameTextFile, const MyString bookContent)
{
    std::ofstream fileBook;
    fileBook.open(nameTextFile.c_str(), std::ios::app);

    if (fileBook.fail())
    {
        std::cout << "Error opening file!\n";
        return;
    }

    fileBook << bookContent << std::endl;

    fileBook.close();
}

void ElectronicLibrary::addBookToLibrary(MyString nameAuthor, MyString bookTitle, MyString nameTextFile, MyString shortDescription, float rating, MyString ISBN)
{
    if (isEmpty())
    {
        this->BooksLibrary = new Book *[capacityLibrary];
    }

    if (capacityLibrary <= currCountBooks)
    {
        resize();
    }

    BooksLibrary[currCountBooks] = new Book(nameAuthor, bookTitle, nameTextFile, shortDescription, rating, ISBN);
    currCountBooks++;
}

void ElectronicLibrary::removeBookFromLibrary(MyString ISBN)
{
    for (size_t i = 0; i < currCountBooks; ++i)
    {
        if (BooksLibrary[i]->getISBN() == ISBN)
        {
            delete BooksLibrary[i];
            shift(i);
            break;
        }
    }
}

MyString ElectronicLibrary::getBookTextFile(MyString ISBN)
{
    MyString nameTextFile;
    for (size_t i = 0; i < currCountBooks; ++i)
    {
        if (BooksLibrary[i]->getISBN() == ISBN)
        {
            nameTextFile = BooksLibrary[i]->getNameTextFile();
            break;
        }
    }
    return nameTextFile;
}

void ElectronicLibrary::deleteFileBook(MyString nameTextFile)
{
    if (remove(nameTextFile.c_str()) != 0)
    {
        std::cout << "Error deleting file!\n";
        std::cout << std::endl;
    }
    else
    {
        std::cout << "File successfully deleted!\n";
        std::cout << std::endl;
    }
}

size_t ElectronicLibrary::getLinesCount(const MyString fileName)
{
    std::ifstream fileBooks;
    fileBooks.open(fileName.c_str());

    if (fileBooks.fail())
        return 0;

    size_t count = 0;

    while (!fileBooks.eof())
    {
        char buffer[BUFF_SIZE];
        fileBooks.getline(buffer, BUFF_SIZE);
        count++;
    }

    fileBooks.close();

    return count;
}

void ElectronicLibrary::printBookPages(const MyString fileName, size_t numberLines)
{
    std::ifstream fileBooks(fileName.c_str(), std::ios::in);

    if (!fileBooks.is_open())
    {
        std::cout << "Error opening file!\n";
        std::cout << std::endl;
        return;
    }

    size_t countLines = 0;

    while ((!fileBooks.eof()) && (countLines < numberLines))
    {
        char buffer[BUFF_SIZE];
        fileBooks.getline(buffer, BUFF_SIZE);
        std::cout << buffer << std::endl;
        countLines++;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    fileBooks.close();
}

void ElectronicLibrary::printBookSentences(const MyString fileName, size_t numberSentences) const
{
    std::ifstream fileBooks;
    fileBooks.open(fileName.c_str(), std::ios::in);

    if (fileBooks.fail())
    {
        std::cout << "Error opening file!\n";
        return;
    }

    char buffer[BUFF_SIZE];

    fileBooks.getline(buffer, BUFF_SIZE);
    size_t countSentences = 0, positionStopReading = 0;

    fileBooks >> buffer;

    for (size_t i = 0; i < BUFF_SIZE; ++i)
    {
        if (buffer[i] == '.' || buffer[i] == '!' || buffer[i] == '?')
            countSentences++;

        if (countSentences == numberSentences)
        {
            positionStopReading = i;
            break;
        }
    }

    for (size_t i = 0; i <= positionStopReading; ++i)
    {
        std::cout << buffer[i];
    }
    std::cout << std::endl;
    std::cout << std::endl;

    fileBooks.close();
}

void ElectronicLibrary::writeToFile() const
{
    std::ofstream fileBooks;
    fileBooks.open("BooksLibrary.txt", std::ios::out);

    if (fileBooks.fail())
    {
        std::cout << "Error while opening file!\n";
        return;
    }

    fileBooks << currCountBooks << std::endl;
    for (size_t i = 0; i < currCountBooks; ++i)
    {
        fileBooks << BooksLibrary[i]->getNameAuthor() << " " << BooksLibrary[i]->getBookTitle() << " " << BooksLibrary[i]->getNameTextFile() << " " << BooksLibrary[i]->getShortDescription() << " " << BooksLibrary[i]->getRating() << " " << BooksLibrary[i]->getISBN() << std::endl;
    }
    fileBooks.close();
}
