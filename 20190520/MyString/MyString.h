#pragma once
#include <string.h>
#include <iostream>

using namespace std;

const int N = 1024;

class MyString
{

public:

    friend ostream& operator<<(ostream& cout, MyString &str);
    friend istream& operator>>(istream& cin, MyString &str);
    
    MyString();
    MyString(const char *);
    MyString(const MyString &);

    ~MyString();

    MyString& operator=(const MyString&);
    MyString& operator=(const char*);

    MyString& operator+=(const MyString &);
    MyString& operator+=(const char *);


    char& operator[](const size_t index);
    const char &operator[](const size_t index) const;

    size_t size() const;
    const char* c_str() const; 

    MyString operator+(const char *str);
    MyString operator+(const MyString str);

    bool operator==(const char *str);
    bool operator==(const MyString str);

    bool operator!=(const char *);
    bool operator!=(const MyString);

    
    friend bool operator<(const MyString &, const MyString &);
    friend bool operator>(const MyString &, const MyString &);
    friend bool operator<=(const MyString &, const MyString &);
    friend bool operator>=(const MyString &, const MyString &);


private:
    char * pString;
    size_t StringSize;
};
