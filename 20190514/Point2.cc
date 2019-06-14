#include <iostream>

using namespace std;

class Point
{
public:
    Point(int x):_x(x), _y(_x){}
    //Point(int x):_y(x), _x(_y){}
    void print();
private:
        int _x;
        int _y;
};

void Point::print(){
    cout << "x = " << _x << endl
        << "y = " << _y << endl;
}

int main(){
    Point t(5);
    t.print();
    return 0;
}
