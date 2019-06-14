#include <iostream>

using namespace std;

class Point
{
public:
    explicit Point(int ix, int iy = 0):_ix(ix), _iy(iy)
    {
        cout << "Point(int, int)" << endl;
    }

   // //委托构造函数
   // Point(int ix):Point(ix, 0)
   // {
   //     cout << "Point(int)" << endl;
   // }

    void print()
    {
        cout << "(" << this->_ix
            << "," << this->_iy 
            << ")" << endl;
    }

    ~Point()
    {
        cout << "~Point" << endl;
    }

private:
    int _ix;
    int _iy;
};

int test0()
{
    Point pt(3);
    pt.print();
  //  隐式转换
  //  int a = 5;
  //  Point pt2 = a;
  //  pt2.print();
    return 0;
}

int main()
{
    test0();
    return 0;
}
