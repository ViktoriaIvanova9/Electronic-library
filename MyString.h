#ifndef __MY_STRING_H
#define __MY_STRING_H

#include <iostream>
#include <cstring>
#include <fstream>

class MyString
{
private:
    char *data;
    size_t size;

    void copyFrom(const char *data, size_t size);
    void clear();

public:
    MyString();
    MyString(const char *data);
    MyString(const MyString &other);
    MyString &operator=(const MyString &other);
    ~MyString();

    const char *getData() const;
    size_t getSize() const;

    char *toLower();

    const char *c_str() const;

    void concat(const MyString& other);
    
    MyString& operator++();
    MyString& operator+=(const MyString& other);

    friend std::ostream &operator<<(std::ostream &os, const MyString &str);
    friend std::istream &operator>>(std::istream &is, MyString &str);
};

bool operator==(const MyString &first, const MyString &second);
bool operator!=(const MyString &first, const MyString &second);
bool operator<(const MyString &first, const MyString &second);

bool isSubstring(MyString first, MyString second);

#endif