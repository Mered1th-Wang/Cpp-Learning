#include "MyString.h"

using namespace std;

int main()
{
    MyString a("1bd");
    MyString b("ffff");

    if(a < b)
    {
        cout << "a < b" << endl; //a < b
    }

    if(a <= b)
    {
        cout << "a <= b" << endl; //a <= b
    }

    if(a > b)
    {
        cout << "a > b" << endl; 
    }

    if(a == a)
    {
        cout << "a = a" << endl; // a = a
    }

    if(a == "1bd")
    {
        cout << "a = 1bd" << endl; // a = 1bd
    }
    
    if(a != b)
    {
        cout << "a != b" << endl; // a != b
    }
    
    MyString c = a + b;
    cout << c << endl; //1bdffff
    
    c += a;
    cout << c << endl; //1bdffff1bd

    MyString d = a + "aaa";
    cout << d << endl; //1bdaaa

    d += "ccc";
    cout << d << endl; //1bdaaaccc

    cout << d.c_str() << endl; //1bdaaaccc
    printf("%s\n", d.c_str()); //1bdaaaccc
    cout << d.size() << endl; //9
    
    cout << d[3] << endl; //a
    d[3] = 'x';
    cout << d[3] << endl; //x
    cout << d << endl; //1bdxaaccc


    MyString test;
    cout << endl << "plz input the string:" << endl;
    cin >> test;
    cout << test << endl;

    return 0;
}
