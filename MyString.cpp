#include "MyString.h"

void MyString::copyFrom(const char *data, size_t size)
{
    this->data = new char[strlen(data) + 1];
    strcpy(this->data, data);

    this->size = size;
}

void MyString::clear()
{
    delete[] data;
    data = nullptr;
}

const char *MyString::getData() const
{
    return data;
}

size_t MyString::getSize() const
{
    return size;
}

MyString::MyString() : data(new char[1]), size(0)
{
    data[0] = '\0';
}

MyString::MyString(const char *str)
{
    if (str == nullptr)
    {
        data = new char[1];
        data[0] = '\0';
        size = 0;
    }
    else
        copyFrom(data, size);
}

MyString::MyString(MyString &&object)
{
    data = object.data;
    size = object.size;

    object.data = nullptr;
    object.size = 0;
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
MyString &MyString::operator=(MyString &&other)
{
    if (this != &other)
    {
        clear();
        data = other.data;
        other.data = nullptr;

        size = other.size;
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

std::ostream &operator<<(std::ostream &os, const MyString &str)
{
    os << str.data;
    return os;
}

std::istream &operator>>(std::istream &is, MyString &str)
{
    delete[] str.data;
    char buff[1024];
    is >> buff;

    str.size = strlen(buff);
    str.data = new char[str.size + 1];
    strcpy_s(str.data, str.size, buff);

    return is;
}

bool operator==(const MyString &first, const MyString &second)
{
    return strcmp(first.c_str(), second.c_str()) == 0;
}

bool operator<(const MyString &first, const MyString &second)
{
    return strcmp(first.c_str(), second.c_str()) < 0;
}

char* MyString::toLower()
{
    char* temp = new char [strlen(data)+1];
    strcpy(temp,this->data);
    for (size_t i = 0; i < this->size; ++i)
    {
        if (temp[i] >= 'A' && temp[i] <= 'Z')
            temp[i] -= 27;
    }
    return temp;
}

bool isSubsring(MyString &str,MyString &substr)
{
    char * tempStr = str.toLower();
    char * tempSubstr = substr.toLower();

    if (strstr(tempStr, tempSubstr)==nullptr)
        return false;
    else
        return true;
}
