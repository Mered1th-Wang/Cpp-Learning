#include <string>
#include <iostream>

using namespace std;

class Person{
public:
    Person(string name, int a):m_Name(name), m_Age(a){}
    
    bool operator==(Person & rhs)
    {
        if(this->m_Name == rhs.m_Name && this->m_Age == rhs.m_Age)
        {
            return true;
        }
        return false;
    }

public:
    string m_Name;
    int m_Age;
};


int main()
{
    Person p1("张三", 10);
    Person p2("张三", 10);
    Person p3("李四", 10);

    if(p1 == p2){
        cout << "p1 = p2" << endl;
    }
    else{
        cout << "p1 != p2" << endl;
    }

    if(p1 == p3){
        cout << "p1 = p3" << endl;
    }
    else{
        cout << "p1 != p3" << endl;
    }
    return 0;
}
