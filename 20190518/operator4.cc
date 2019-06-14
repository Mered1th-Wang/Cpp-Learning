#include <iostream>

using namespace std;

class Person{
public:
    Person() {}
    Person(int a, int b) :m_A(a), m_B(b){}

    Person operator+(Person & rhs)
    {
        Person temp;
        temp.m_A = this->m_A + rhs.m_A;
        temp.m_B = this->m_B + rhs.m_B;
        return temp;
    }

    int m_A;
    int m_B;
};

int main()
{
    Person p1(10, 20);
    Person p2(20, 30);
    Person p3 = p1 + p2;
    cout << p3.m_A << ", " << p3.m_B << endl;
    return 0;
}
