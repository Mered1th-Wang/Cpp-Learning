#include <cstdio>
#include <iostream>
using std::cout;
using std::endl;

int num = 1;

namespace wd{
int num = 10;

void display(int num){
    cout << "wd::display()" << endl;
    cout << "num = " << num <<endl;
    cout << "wd::num = " << wd::num <<endl;
    cout << "num = " << ::num <<endl;
    ::printf("hello, world\n");
}
}

int main()
{
    int x = 100;
    wd::display(x);
    return 0;
}

