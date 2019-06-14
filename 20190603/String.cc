#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class String{
public:
    String(const char * pstr)
        :_pstr(new char[strlen(pstr + 1)]())
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }

    String(const String & rhs)
        :_pstr(new char[strlen(rhs._pstr) + 1]())
    {
        cout << "String(const String & rhs)" << endl;
        if(this != &rhs){
            delete [] _pstr;
            _pstr = new char[strlen(rhs._pstr)]();
            strcpy(_pstr, rhs._pstr);
        }
    }

    String & operator=(const String & rhs){
        cout << "String & operator=(const String & rhs)" << endl;
        if(this != &rhs){
            delete [] _pstr;
            _pstr = new char[strlen(rhs._pstr)]();
            strcpy(_pstr, rhs._pstr);
        }
        return *this;
    }

    String(String && rhs)
        :_pstr(rhs._pstr)
    {
        cout << "String(String &&)" << endl;
        rhs._pstr = nullptr;
    }

    String & operator=(String && rhs)
    {
        cout << "String & operator=(String && rhs)" << endl;
        if(this != &rhs){
            delete [] _pstr;
            _pstr = rhs._pstr;
            rhs._pstr = nullptr;
        }
        return *this;
    }

    ~String()
    {
        if(_pstr) delete [] _pstr;
        
        cout << "~String()" << endl;
    }

    friend ostream & operator<<(ostream & os, const String & rhs);


private:
    char * _pstr;
};

ostream & operator<<(ostream & os, const String & rhs){
    os << rhs._pstr;
    return os;
}

void test0()
{
    vector<String> strs;
    strs.push_back("hello, world");
    cout << endl;

    String str1 = "test";
    //strs.push_back(str1); 
    strs.push_back(std::move(str1));
    cout << endl;
}

void test1()
{
    String str1("hangzhou");
    String str2("shenzhen");
    cout << "str1 = " << str1 << endl;
    str2 = std::move(str1);
    cout << "str2 = " << str2 << endl;
    cout << "str1 = " << str1 << endl; //cout 流error
    str1 = "xxxx";
    cout.clear();
    cout << endl;
    cout << "str1 = " << str1 << endl; //cout 流error
}

String & getString0(){}

String s1("hello");

String getString()
{
    String str("hello");
    return str;
    //return s1;
}

void test2()
{
    int a = 1, b = 2;
    cout << "a = " << a << ", b = " << b << endl;
    b = std::move(a);
    cout << "a = " << a << ", b = " << b << endl;
}

void test3()
{
    getString();
}

void test4()
{
    getString0();
}

int main()
{
    test4();
    return 0;
}
