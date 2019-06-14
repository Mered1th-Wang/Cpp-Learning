#include <iostream>

using namespace std;

class MyPrint{
    public:
        void operator()(string s)
        {
            cout << s << endl;
        }
};

class MyAdd{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

int main()
{
    MyPrint myPrint;
    myPrint("hello");
    MyPrint()("world");
    MyAdd myAdd;
    cout << myAdd(1, 2) << endl;

    cout << MyAdd()(1, 1) << endl; // 匿名对象

    return 0;
}
