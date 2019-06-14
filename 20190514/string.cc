#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

int count = 0;

class String
{
public:
    String();
    String(const char *pstr);
    String(const String &rhs);
    String& operator=(const String & rhs);
    ~String();

    void print();
private:
    char * _pstr;
};

int main(){

    String str1;
    str1.print();

    cout << endl;
    String str2 = "Hello, world";
    str2.print();
    
    cout << endl;
    String str3("wangdao");
    str3.print();

    cout << endl;
    String str4 = str3;
    str4.print();

    cout << endl;
    str4 = str2;
    str4.print();

    return 0;
}

String::String(const char *pstr): _pstr(new char[strlen(pstr) + 1]())
{
    strcpy(this->_pstr, pstr);
    count++;
    cout << "构造函数调用, count = " << count << endl;
}
String::String(const String &rhs): _pstr(new char[strlen(rhs._pstr) + 1]())
{
    count++;
    strcpy(this->_pstr, rhs._pstr);
    cout << "拷贝函数调用, count = " << count << endl;
}
String::~String()
{
    count--;
    delete [] _pstr;
    cout << "析构函数调用, count = "<< count << endl;
}

void String::print()
{
    cout << "_pstr = " << _pstr << endl;
}

String::String():_pstr(new char)
{
    count++;
    cout << "构造函数调用, count = "<< count << endl;
    _pstr[0] = 0;
}

String& String::operator=(const String & rhs)
{
    if(this != &rhs)
    {
        delete [] _pstr;
        _pstr = new char[strlen(rhs._pstr) + 1];
        strcpy(this->_pstr, rhs._pstr);
        cout << "赋值 = 函数调用" << endl;
        return * this;
    }
}
