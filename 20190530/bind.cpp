#include <iostream>
#include <functional>

using namespace std;
using namespace std::placeholders;

void display() { cout << "display()" << endl; }

void (*f)() = display;

typedef void (*Function)();

int test0()
{
    f();
    Function f1 = display;
    f1();
    return 0;
}

void add(int x, int y)
{
    cout << "x + y = " << x + y << endl;
}

//template<typename... Args>
//void add(Args... args)
//{
//    cout << args...<< endl;
//}

struct Example
{
    void add(int x, int y)
    {
        cout << "Example::add()" << endl;
        cout << "x + y = " << x + y << endl; 
    }
};

void print(int x1, int x2, int & x3, int x4)
{
    cout << "(" << x1
        << "," << x2
        << "," << x3
        << "," << x4
        << ")" << endl;

}

int main()
{
    auto f = display;
    f();

    auto f1 = bind(&add, 1, 2);
    f1();

    Example example;
    auto f2 = bind(&Example::add, &example, 1, 2);
    f2();

    auto f3 = bind(&Example::add, example, 1, 2);
    f3();


    auto f4 = bind(&Example::add, example, _1, _2);
    f4(11, 22, 33, 44); //33 44 失效

    int a = 100;
    function<void(int, int)> f5 = bind(print, _1, _2, ref(a), a);
    a = 101;
    f5(11, 22);



    return 0;
}
