#include <iostream>

using namespace std;

class Test
{
public:
    Test():x(0), y(1){}
public:
    int x, y;
};

int main()
{
    Test t;
    int * p = (int*)&t;
    cout << *p << endl;
    p++;
    cout << *p << endl;
    return 0;
}
