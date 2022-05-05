#ifndef __MY_STRING_H
#define __MY_STRING_H

#include <iostream>
#include <cstring>

class MyString
{
private:
    char *data;
    size_t size;

    void copyFrom(const char *data, size_t size);
    void clear();


public:
    const char* getData() const;
    size_t getSize() const;

    MyString();
    MyString(const char *str);

    MyString(MyString &&object);

    MyString(const MyString &other);

    MyString &operator=(const MyString &other);
    MyString &operator=(MyString &&other);

    ~MyString();

    char* toLower();

    const char* c_str() const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);

};

bool operator==(const MyString& first,const MyString& second);
bool operator<(const MyString& first,const MyString& second);

bool isSubstring(MyString& first, MyString& second);

#endif