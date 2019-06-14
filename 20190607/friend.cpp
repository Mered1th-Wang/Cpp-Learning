#include <iostream>

using namespace std;

class B;
class A
{
    friend class B;
public:
    void Display() { cout << _a << endl;  }
private:
    int _a;
};

class B
{
public:
    void SetVal() { Aobject._a = 10; }
    void Display() { Aobject.Display(); }
private:
    A Aobject;
};

int main()
{
    B b;
    b.SetVal();
    b.Display();
    return 0;
}
