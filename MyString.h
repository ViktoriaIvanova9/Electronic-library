#ifndef __MY_STRING_H
#define __MY_STRING_H

#include <iostream>
#include <cstring>
#include <fstream>

/// Help class which prevents writing the Big four in every other class. More convenient.
class MyString
{
private:
    char *data;
    size_t size;
    size_t capacity;

    void copyFrom(const char *data, size_t size);
    void clear();
    void resize();

public:
    MyString();
    MyString(const char *data);
    MyString(const MyString &other);
    MyString &operator=(const MyString &other);
    ~MyString();

    const char *getData() const; /// constant function which returns data
    size_t getSize() const;      /// returning size of the array

    char *toLower(); /// turning all capital letters into small ones

    const char *c_str() const;

    MyString &operator++(); /// returning a pointer to the array of chars

    MyString &operator+=(char c); /// adding a new char to the array and increasing the size

    static bool isSubstring(MyString str, MyString substr); /// checking if a object of type MyString is substring of another object of type MyStirng8

    friend std::ostream &operator<<(std::ostream &os, const MyString &str);
    friend std::istream &operator>>(std::istream &is, MyString &str);
};

bool operator==(const MyString &first, const MyString &second); /// check if first==second
bool operator!=(const MyString &first, const MyString &second); /// check if first!= second
bool operator<(const MyString &first, const MyString &second);  /// check if first<second

#endif