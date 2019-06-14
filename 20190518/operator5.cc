#include <iostream>

using namespace std;

class MyInteger{
    friend ostream& operator<<(ostream &cout, MyInteger &m);
public:
    MyInteger():m_Num(0){}
    MyInteger(int num): m_Num(num){}
   
    MyInteger& operator++()
    {
        this->m_Num++;
        return *this;
    }

    MyInteger operator++(int)
    {
        MyInteger tmp = *this;
        this->m_Num++;
        return tmp;
    }

private:
    int m_Num;
};

ostream& operator<<(ostream &cout, MyInteger &p)
{
    cout << p.m_Num;
    return cout;
}


int main()
{
    MyInteger myInt;
    cout << myInt << endl;
    ++myInt;
    cout << myInt << endl;
    myInt++;
    cout << myInt << endl;

    cout << endl;
    cout << ++(++myInt) << endl;
}
