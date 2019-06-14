#include <iostream>
#include <memory>

using namespace std;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
        : _ix(ix)
          , _iy(iy)
    {   cout << "Point(int,int)" << endl;   }

    void print() const
    {
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;

    }

    ~Point() {  cout << "~Point()" << endl; }

private:
    int _ix;
    int _iy;
};

void test0()
{
    Point * pt = new Point(1, 2);
    unique_ptr<Point> up1(pt);
    //unique_ptr<Point> up2(pt);

    up1->print();
    //up2->print();
}

void test1()
{
    Point * pt = new Point(1, 2);
    unique_ptr<Point> up1(pt);
    shared_ptr<Point> sp2(pt);
     
    up1->print();
    sp2->print();
}

int main()
{
    test1();
    return 0;
}
