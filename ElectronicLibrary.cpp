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

bool ElectronicLibrary::isEmptyArr()
{
    return currCountBooks == 0;
}

ElectronicLibrary::ElectronicLibrary()
{
    BooksLibrary = nullptr;
    currCountBooks = 0;
    capacityLibrary = 0;
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

void ElectronicLibrary::swap(Book *first, Book *second)
{
    Book temp = *first;
    *first = *second;
    *second = temp;
}

void ElectronicLibrary::selectionSort(Book **arrOfBooks, size_t booksCount, unsigned property, bool order)
{
    size_t i, j, minIndex;

    for (int i = 0; i < booksCount - 1; ++i)
    {
        minIndex = i;

        for (j = i + 1; j < booksCount; ++i)
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
                    if (arrOfBooks[minIndex]->getRating() < arrOfBooks[j]->getRating()) // descending order
                        minIndex = j;
                }
                else
                {
                    if (arrOfBooks[j]->getRating() < arrOfBooks[minIndex]->getRating()) // ascending order
                        minIndex = j;
                }
            }
        }

        swap(arrOfBooks[minIndex], arrOfBooks[i]);
    }
}

/*Извежда последователно за всяка книга следната информация: <заглавие>, <автор>, <ISBN>.
Изведеният списък да е сортиран възходящо или низходящо (по желание на потребителя) по едно
от следните полета: заглавие, автор, рейтинг, избрани от потребителя*/
void ElectronicLibrary::sortBooksBy(int property, int order)
{
    if (isEmptyArr())
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

    else if(order==2) // descending order sort
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
        std::cout << BooksLibrary[i]->getBookTitle() << ", " << BooksLibrary[i]->getNameAuthor() << ", " << BooksLibrary[i]->getISBN() << std::endl;
    }
}

/*Извежда на екрана подробна информация за книга с въведени от потребителя заглавие, автор, ISBN или част от описание.
При първите три критерия се изисква точно съвпадение, а при описанието може въведеният от потребителя низ
да се съдържа в описанието. Търсене на книга по зададен критерий да игнорира регистъра на буквите (малки или големи).*/
void ElectronicLibrary::findBook(MyString bookTttle, MyString bookAuthor, MyString ISBN, MyString shortDescription)
{
    for (size_t i = 0; i < currCountBooks; ++i)
    {
        if ((BooksLibrary[i]->getBookTitle() == bookTttle && BooksLibrary[i]->getNameAuthor() == bookAuthor && BooksLibrary[i]->getISBN() == ISBN) || (isSubstring(BooksLibrary[i]->getShortDescription(), shortDescription)))
        {
            std::cout << "The name of the book is: " << BooksLibrary[i]->getBookTitle() << std::endl;
            std::cout << "The author of the book is: " << BooksLibrary[i]->getNameAuthor() << std::endl;
            std::cout << "The name of text file where the book is: " << BooksLibrary[i]->getNameTextFile() << std::endl;
            std::cout << "The short description of the book is: " << BooksLibrary[i]->getShortDescription() << std::endl;
            std::cout << "The reting of the book is: " << BooksLibrary[i]->getRating() << std::endl;
            std::cout << "The ISBN of the book is: " << BooksLibrary[i]->getISBN() << std::endl;
        }
    }
}

void ElectronicLibrary::addBookToTextFile(MyString nameAuthor, MyString bookTitle, const MyString nameTextFile, MyString shortDescription, float rating, MyString ISBN) const
{
    std::ofstream fileData("BooksLibrary.txt", std::ios::app);

    if (!fileData.is_open())
    {
        std::cout << "Error opening file!";
        return;
    }

    fileData << nameAuthor << ", " << bookTitle << ", " << shortDescription << ", " << rating << ", " << ISBN << std::endl;

    fileData.close();

    std::ofstream fileBook(nameTextFile.c_str(), std::ios::app);

    if (!fileBook.is_open())
    {
        std::cout << "Error opening file!";
        return;
    }

    MyString bookContent;
    std::cin >> bookContent;

    fileBook << bookContent << std::endl;

    fileBook.close();
}

/*Добавя в библиотеката нова книга, като въвежда пълна информация за нея.*/
void ElectronicLibrary::addBookToLibrary(MyString nameAuthor, MyString bookTitle, MyString nameTextFile, MyString shortDescription, float rating, MyString ISBN)
{
    if (isEmptyArr())
    {
        this->BooksLibrary = new Book *[DEFAULT_COUNT_BOOKS];
    }

    if (capacityLibrary <= currCountBooks)
    {
        resize();
    }

    BooksLibrary[currCountBooks] = new Book(nameAuthor, bookTitle, nameTextFile, shortDescription, rating, ISBN);
    currCountBooks++;
}

/*Премахване на книга от библиотеката, като в този случай се дава възможност за се изтрие и файла, свързан с книгата.*/
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

void removeBookFromTextFile(MyString ISBN, const MyString nameTextFile)
{
}

void ElectronicLibrary::printBookInfo() const
{
}
