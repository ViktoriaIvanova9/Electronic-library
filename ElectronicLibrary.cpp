#include "ElectronicLibrary.h"

void ElectronicLibrary::copyFrom(const Book **BooksLibrary, size_t currCountBooks, size_t capacityLibrary)
{
    this->currCountBooks = currCountBooks;
    this->capacityLibrary = capacityLibrary;

    BooksLibrary = new Book *[currCountBooks];

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

ElectronicLibrary::ElectronicLibrary(const Book **BooksLibrary, size_t currCountBooks, size_t capacityLibrary)
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

void helpChoise()
{
    std::cout << "For sorting all books choose 1\n";
    std::cout << "For finding a book choose 2\n";
    std::cout << "For adding new book choose 3\n";
    std::cout << "For removing any book choose 4\n";
    std::cout << "For printing any book choose 5\n";

    std::cout << "For exiting library choose 0\n";
}

/*Извежда последователно за всяка книга следната
информация: <заглавие>, <автор>, <ISBN>.
Изведеният списък да е сортиран възходящо или
низходящо (по желание на потребителя) по едно
от следните полета: заглавие, автор, рейтинг,
избрани от потребителя*/
void ElectronicLibrary::sortBooksBy(int order, int criteria)
{
    if (isEmptyArr())
    {
        std::cout << "There aren't books in this library.\n";
        return;
    }

    if (order == 1)
    {
        // sortirai vuzhodqshto
        if (criteria == 1)
        {
            // sortirai po zaglavie
        }
        else if (criteria == 2)
        {
            // sort po author
        }
        else
        {
        } // sort po rating
    }

    else
    {
        // sortirai nizhodqshto
        if (criteria == 1)
        {
            // sortirai po zaglavie
        }
        else if (criteria == 2)
        {
            // sort po author
        }
        else
        {
        } // sort po rating
    }
}

void ElectronicLibrary::printSortedBooks() const
{
}

/*Извежда на екрана подробна информация за
книга с въведени от потребителя заглавие, автор,
ISBN или част от описание. При първите три
критерия се изисква точно съвпадение, а при
описанието може въведеният от потребителя низ
да се съдържа в описанието. Търсене на книга по
зададен критерий да игнорира регистъра на
буквите (малки или големи).*/
Book &ElectronicLibrary::findBook()
{
}

void ElectronicLibrary::addBookToTextFile(const Book &obj)
{
    std::ofstream file("BooksLibrary.txt");

    if (!file.is_open())
    {
        std::cout << "Error opening file!";
        return;
    }

    file << obj.getNameAuthor() << "," << obj.getBookTitle() << "," << obj.getRating() << "," << obj.getISBN() << "," << obj.getNameTextFile() << std::endl;

    file.close();
}

/*Добавя в библиотеката нова книга, като въвежда
пълна информация за нея.*/
void ElectronicLibrary::addBookToLibrary(const Book &obj)
{
    if (isEmptyArr())
    {
        this->BooksLibrary = new Book *[DEFAULT_COUNT_BOOKS];
    }

    if (capacityLibrary <= currCountBooks)
    {
        resize();
    }

    BooksLibrary[currCountBooks] = new Book(obj.getNameAuthor(), obj.getBookTitle(), obj.getNameTextFile(), obj.getShortDescription(), obj.getRating(), obj.getISBN());
    currCountBooks++;
}

/*Премахване на книга от библиотеката, като в
този случай се дава възможност за се изтрие и
файла, свързан с книгата.*/
void ElectronicLibrary::removeBookFromLibrary(const Book &obj)
{
    for (size_t i = 0; i < currCountBooks; ++i)
    {
        if (strcmp(BooksLibrary[i]->getISBN(), obj.getISBN()) == 0)
        {
            delete BooksLibrary[i];
            shift(i);
        }
    }
}

void ElectronicLibrary::printBookInfo() const
{
}
