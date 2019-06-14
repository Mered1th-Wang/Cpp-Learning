#include <iostream>

using namespace std;

class Person{
public:
    Person(int age):m_Age(age){}
    void showAge()
    {
        cout << "Age: " << m_Age << endl;
    }
    ~Person()
    {
        cout << "~Person()" << endl;
    }

private:
    int m_Age;
};

class smartPointer{
public:
    smartPointer(Person *person)
    {
        this->person = person;
    }

    Person * operator->()
    {
        return this->person;
    }
    
    Person& operator*()
    {
        return *this->person;
    }

    ~smartPointer()
    {
        if(this->person != nullptr)
        {
            delete this->person;
            this->person = nullptr;
        }
    }

private:
        Person *person;
};


void test()
{
    Person * p1 = new Person(10);
    delete p1; //析构函数手动调用
    
    cout << "智能指针：" << endl;
    smartPointer sp(new Person(10));

    sp->showAge();
    (*sp).showAge();
}

int main()
{
    test();
    return 0;
}
