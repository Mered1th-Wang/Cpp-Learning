#include "MyString.h"

using namespace std;

ostream& operator<<(ostream& cout, MyString &str)
{
    cout << str.pString;
    return cout;
}

istream& operator>>(istream& cin, MyString &str)
{
    if(nullptr != str.pString)
    {
        delete [] str.pString;
        str.pString = nullptr;
    }
    char buf[N] = {0};
    cin >> buf;
    str.pString = new char[strlen(buf) + 1]();
    strcpy(str.pString, buf);
    str.StringSize = strlen(buf);
    return cin;
}

MyString::MyString()
{
    this->pString = nullptr;
    this->StringSize = 0;
}

MyString::MyString(const char *str):pString(new char[strlen(str) + 1]())
{
    strcpy(this->pString, str);
    StringSize = strlen(str);
}

MyString::MyString(const MyString & str)
{
    if(this != &str)
    {
        this->pString = new char[str.StringSize + 1]();
        strcpy(this->pString, str.pString);
        this->StringSize = str.StringSize;
    }
}

MyString::~MyString()
{
    if(this->pString != nullptr)
    {
        delete [] this->pString;
        this->pString = nullptr;
        this->StringSize = 0;
    }
}

MyString& MyString::operator=(const MyString& str)
{
    if(this != &str)
    {
        delete [] this->pString;
        this->pString = new char[str.StringSize + 1]();
        strcpy(this->pString, str.pString);
        this->StringSize = str.StringSize;
        return *this;
    }
}

MyString& MyString::operator=(const char* str)
{
    if(this->pString != nullptr)
    {
        delete [] this->pString;
        this->pString = new char[strlen(str) + 1]();
        strcpy(this->pString, str);
        this->StringSize = strlen(str);
        return *this;
    }
}

MyString& MyString::operator+=(const MyString &str)
{
    MyString tmp(*this);
    this->StringSize = this->StringSize + str.StringSize;
    this->pString = new char[StringSize + 1]();
    strcpy(this->pString, tmp.pString);
    strcat(this->pString, str.pString);
    return *this;
}

MyString& MyString::operator+=(const char *str)
{
    MyString tmp(*this);
    this->StringSize = this->StringSize + strlen(str);
    this->pString = new char[StringSize + 1]();
    strcpy(this->pString, tmp.pString);
    strcat(this->pString, str);
    return *this;
}

char& MyString::operator[](const size_t index)
{
    if(index < this->StringSize)
    {
        return this->pString[index];
    }
    else
    {
        static char nullchar = '\0';
        cout << "index out of bounds exception!" << endl;
        return nullchar;
    }
}

const char& MyString::operator[](const size_t index) const
{
    return this->pString[index];
}

size_t MyString::size() const
{
    return this->StringSize;
}

const char* MyString::c_str() const
{
    return this->pString;
}


MyString MyString::operator+(const char *str)
{
    size_t len = this->StringSize + strlen(str);
    char * tmp = new char[len + 1]();
    strcpy(tmp, this->pString);
    strcat(tmp, str);
    MyString res(tmp);
    return res;
}

MyString MyString::operator+(const MyString str)
{
    size_t len = this->StringSize + str.StringSize;
    char * tmp = new char[len + 1]();
    strcat(tmp, this->pString);
    strcat(tmp, str.pString);
    MyString res(tmp);
    return res;
}

bool MyString::operator==(const char *str)
{
    if(this->StringSize == strlen(str) && (!strcmp(this->pString, str)))
    {
        return true;
    }
    else return false;
}

bool MyString::operator==(const MyString str)
{
    if(this->StringSize == str.StringSize && (!strcmp(this->pString, str.pString)))
    {
        return true;
    }
    else return false;
}

bool MyString::operator!=(const char *str)
{
    return !(*this == str);
}
bool MyString::operator!=(const MyString str)
{
    return !(*this == str);
}

bool operator<(const MyString &lhs, const MyString &rhs)
{
    if(strcmp(lhs.pString, rhs.pString) < 0)
    {
        return true;
    }
    else return false;
}

bool operator>(const MyString &lhs, const MyString &rhs)
{
    return !(lhs < rhs);
}
bool operator<=(const MyString &lhs, const MyString &rhs)
{
    return !(lhs > rhs);
}
bool operator>=(const MyString &lhs, const MyString &rhs)
{
    return !(lhs < rhs);
}
