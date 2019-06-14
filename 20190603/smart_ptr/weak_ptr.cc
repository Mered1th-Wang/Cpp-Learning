#include <iostream>
#include <memory>

using namespace std;

class Parent;
class Child
{
public:
    Child() { cout << "Child()" << endl; }
    ~Child() { cout << "~Child()" << endl; }

    weak_ptr<Parent> _pParent;
};

class Parent
{
public:
    Parent() { cout << "Parent()" << endl; }
    ~Parent() { cout << "~Parent()" << endl; }

    shared_ptr<Child> _pChild;
};

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

int test0()
{
    shared_ptr<Parent> pParent(new Parent());
    shared_ptr<Child> pChild(new Child);

    cout << "pParent's use_count = " << pParent.use_count() << endl;
    cout << "pChild's use_count = " << pChild.use_count() << endl;

    pParent->_pChild = pChild;
    pChild->_pParent = pParent;

    cout << "pParent's use_count = " << pParent.use_count() << endl;
    cout << "pChild's use_count = " << pChild.use_count() << endl;

    return 0;
}

void test1()
{
    weak_ptr<Point> wp;
    {
        shared_ptr<Point> sp(new Point(1, 2));
        wp = sp;

        cout << "wp's use_count = " << wp.use_count() << endl;
        cout << "sp's use_count = " << sp.use_count() << endl;
        cout << "wp's expired  = " << wp.use_count() << endl;

        shared_ptr<Point> sp2 = wp.lock();
        if(sp2){
            cout << "wp ->shared_ptr" << endl;
            sp2->print();
        }else{
            cout << "wp failed" << endl;
            sp2->print();
        }
    }

    shared_ptr<Point> sp2 = wp.lock();
    if(sp2){
        cout << "wp ->shared_ptr" << endl;
        sp2->print();
    }else{
        cout << "wp failed" << endl;
        sp2->print();
    }
    cout << endl << "退出语句块" << endl;
    cout << "wp's expired = " << wp.expired() << endl;
}

int main()
{
    test1();
    return 0;
}
