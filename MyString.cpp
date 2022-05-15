#include "MyString.h"

void MyString::copyFrom(const char *data, size_t size)
{
    this->data = new char[strlen(data) + 1];
    strcpy(this->data, data);

    this->size = strlen(data);
}

void MyString::clear()
{
    delete[] data;
    data = nullptr;
}

void MyString::resize()
{
    this->capacity *= 2;
    char *tempArr = new char[this->capacity];
    for (int i = 0; i < this->size; ++i)
    {
        tempArr[i] = this->data[i];
    }

    tempArr[size] = '\0';
    delete[] this->data;
    this->data = tempArr;
}

const char *MyString::getData() const
{
    return data;
}

size_t MyString::getSize() const
{
    return size;
}

MyString::MyString() : data(new char[1]), size(0), capacity(1)
{
    data[0] = '\0';
}

MyString::MyString(const char *data)
{
    copyFrom(data, size);
}

MyString::MyString(const MyString &other)
{
    copyFrom(other.data, other.size);
}

MyString &MyString::operator=(const MyString &other)
{
    if (this != &other)
    {
        clear();
        copyFrom(other.data, other.size);
    }
    return *this;
}

MyString::~MyString()
{
    clear();
}

const char *MyString::c_str() const
{
    return data;
}

MyString &MyString::operator++()
{
    for (size_t i = 0; i < size; ++i)
        data[i]++;

    return *this;
}

MyString &MyString::operator+=(char c)
{
    if (this->size >= this->capacity - 1)
    {
        resize();
    }
    data[size++] = c;
    data[size] = '\0';

    return *this;
}

char *MyString::toLower()
{
    char *temp = new char[strlen(data) + 1];
    strcpy(temp, this->data);
    for (size_t i = 0; i < this->size; ++i)
    {
        if (temp[i] >= 'A' && temp[i] <= 'Z')
            temp[i] -= 27;
    }
    return temp;
}

bool MyString::isSubstring(MyString str, MyString substr)
{
    char *tempStr = str.toLower();
    char *tempSubstr = substr.toLower();

    /// using strstr() function which returns pointer to the first occurence of the substr in str and nullptr if substr is not part of str
    return !strstr(tempStr, tempSubstr) ? false : true; 
}

std::ostream &operator<<(std::ostream &os, const MyString &str)
{
    os << str.data;
    return os;
}

std::istream &operator>>(std::istream &is, MyString &str)
{
    const int BUFF_SIZE = 1024;
    delete[] str.data;
    char buff[BUFF_SIZE];
    is >> buff;

    str.size = strlen(buff);
    str.data = new char[str.size + 1];
    strcpy(str.data, buff);

    return is;
}

bool operator==(const MyString &first, const MyString &second)
{
    return strcmp(first.c_str(), second.c_str()) == 0;
}

bool operator!=(const MyString &first, const MyString &second)
{
    return !(first == second);
}

bool operator<(const MyString &first, const MyString &second)
{
    return strcmp(first.c_str(), second.c_str()) < 0;
}


