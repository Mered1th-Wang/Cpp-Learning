#include <iostream>

using namespace std;

int main()
{
    int num = 100;
    int num2 = 1;
    int const * p2 = &num;
    //*p2 = 10;
    p2 = &num2;
    cout << "*p2 = " << *p2 << endl;
    return 0;
}

