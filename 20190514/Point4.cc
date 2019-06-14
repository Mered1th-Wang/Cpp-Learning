#include <cstring>
#include <iostream>

using namespace std;

//class Pet{
//public:
//    void print()
//    {
//        cout << "x = " << x << endl;
//    }
//private:
//    int x;
//};

class Point
{
public:
    Point(int x = 0, int y = 0, const char * s = "no shape"):_x(x), _y(y), shape(new char[strlen(s) + 1]())
    {
        strcpy(shape, s);
        cout << "构造函数调用" << endl;
    }
    Point(const Point & rhs) 
    {
        //if(this != &rhs)
        //{
            shape = new char[strlen(rhs.shape) + 1]();
            strcpy(shape, rhs.shape);
            this->_x = rhs._x;
            this->_y = rhs._y;
            cout << "拷贝构造函数调用" << endl;
        //}
    }
#if 1
    Point & operator=(const Point & rhs)
    {
        this->_x = rhs._x;
        this->_y = rhs._y;
        this->shape = rhs.shape;
        cout << "调用 = 运算符" << endl;

        return * this;
    }
#endif
    void print()
    {
        cout << "(" << this->_x << ", " << this->_y << ")" << 
            "    shape : " << this->shape << endl << endl;
        printf("%p\n", this);
    }

  //  void setthis(Pet &x)
  //  {
  //      this = &x;
  //  }

    ~Point()
    {
        cout << "析构函数调用" << endl;
    }
private:
    int _x;
    int _y;
    char *shape;
};

int test()
{
    Point pt(1, 2, "yuan");
    cout << "pt = ";
    pt.print();

    Point pt2(pt);
    cout << "pt2 = ";
    pt2.print();


    Point pt3(5, 6, "zhengfangxing");
    cout << "pt3 = ";
    pt3.print();


    pt3 = pt2 = pt;
    cout << "pt3 = ";
    pt3.print();

    pt2 = pt2;
    cout << "pt2 = ";
    pt2.print();
    
    Point *pt4 = new Point(21, 22, "tuoyuanxing");
    pt4->print();

    return 0;
}

//void test1()
//{
//    Point pt;
//    Pet pp;
//    pt.setthis(pp);
//}

int main()
{
    test();
    return 0;
}
