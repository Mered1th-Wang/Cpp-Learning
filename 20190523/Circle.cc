#include <iostream>

using namespace std;

const double PI = 3.14;

class Circle
{
public:
    Circle():_r(0){}
    Circle(double r):_r(r){}
    double getArea()
    {
        return PI * this->_r * this->_r;
    }
    double getPerimeter()
    {
        return 2 * PI * this->_r;
    }
    void show()
    {
        cout << "Area = " << PI * this->_r * this->_r << endl
            << "Perimeter = " <<  2 * PI * this->_r << endl;
    }
private:
    double _r;
};

class Cylinder: public Circle
{
public:
    Cylinder(double r, double h):Circle(r), _h(h){}
    double getVolume()
    { 
        return getArea() * this->_h; 
    }
    void showVolume()
    {
        cout << "getVolume = " << getArea() * this->_h << endl; 
    }
private:
    double _h;
};

int main()
{
    Circle t1;
    t1.show();
    Circle t2(5);
    t2.show();

    Cylinder t3(5, 1);
    t3.showVolume();
    return 0;
}
