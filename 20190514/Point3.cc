#include <iostream>

using namespace std;

class Point 
{   

public:
    Point(int x = 0, int y = 0) : _x(x), _y(y){}
    void print();
    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
        int _x;
        int _y;
};

void Point::print(){
    cout << "(" << _x << ", " << _y << ")" << endl;
}

int main(){
    Point t(2,3);
    t.print();
    return 0;
}
