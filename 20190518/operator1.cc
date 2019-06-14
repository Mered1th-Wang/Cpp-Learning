#include <string.h>
#include <iostream>

using namespace std;

class Person{
public:
    Person(int a):m_A(a){}
    int m_A;
};

class Person2{
public:
    Person2(const char * name):pName(new char[strlen(name) + 1])
    {
        strcpy(this->pName, name);
    }
    ~Person2()
    {
        if(this->pName != NULL)
        {
            delete[] this->pName;
            this->pName = NULL;
        }
    }
    Person2& operator=(const Person2 &p)
    {
        if(this != &p)
        {
            delete[] this->pName;
            this->pName = new char[strlen(p.pName) + 1];
            strcpy(this->pName, p.pName);
            return *this;
        }
    }
    char *pName;
};


void test()
{
    Person p1(10);
    Person p2(0);

    p2 = p1;

    cout << p2.m_A << endl;
}

void test2()
{
    Person2 p1("张三");
    Person2 p2("李四");
    p2 = p1;
    cout << p2.pName << endl;

    cout << endl;
    Person2 p3("1");
    p3 = p2 = p1;
    cout << p3.pName << endl;
}

int main()
{
    test();
    test2();
    return 0;
}
