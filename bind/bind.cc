#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

void display()
{
    cout << "display()" << endl;
}

void (*f)() = display;

typedef void (*Function)();

void add(int x, int y)
{
    cout << "x + y = " << x + y << endl;
}

void print(int x1, int x2, int & x3, int x4)
{
    cout << x1 << endl
        << x2 << endl
        << x3 << endl
        << x4 << endl;
}

struct Example
{
    void add(int x, int y)
    {
        cout << "Example::add()" << endl;
        cout << "x + y = " << x + y << endl; 
    }
};

int main()
{
    f();
    Function f1 = display;
    f1();
    
    auto f2 = display;
    f2();

    auto f3 = bind(add, 1, 2);
    f3();

    //对于成员函数，绑定时必须要加上取地址符号
    Example example;
    auto f4 = bind(&Example::add, &example, 1, 2);
    f4();
    
    //this指针可以传地址，也可以传对象
    //bind绑定参数时，采用值传递
    auto f5 = bind(&Example::add, example, 1, 2);
    f5();
 
    auto f6 = bind(&Example::add, &example, _1, _2);
    f6(11, 12);

    int a = 100, b = 10;
    auto f7 = bind(print, _3, _4, ref(a), b);
    f7(11, 22, 1111, 2222, 33333,321321321);

    //function称作函数的容器，只能保存一个函数
    function<void(int, int)> fun = bind(print, _1, _2, ref(a), a); 
    fun(11, 22);

    cout << "------------" << endl;
    function<void(int, int, int, int)> fun2 = bind(print, _1, 100, ref(a), a);
    fun2(111, 100, 200, 300);

    cout << "------------" << endl;
    function<void()> fun3 = display;
    fun3();
    fun3 = bind(&Example::add, Example(), 1, 2);
    fun3();

    return 0;
}
