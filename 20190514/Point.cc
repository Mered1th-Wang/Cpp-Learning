#include <iostream>

using namespace std;

class Point
{
public:
    Point():_x(0), _y(0)
    {
        cout << "Point()" << endl;
    }
    Point(const int x, const int y):_x(x), _y(y)
    {
        cout << "Point(int, int)" << endl;
    }
    void print();
private:
        int _x;
        int _y;
};

int main(){
    Point p1;
    p1.print();
    Point p2(5, 6);
    p2.print();
}

void Point::print()
{
    cout << "(" << this->_x << ", " << this->_y << ")" << endl;
}
