#include <iostream>

using namespace std;

const double PI = 3.14;

class Figure
{
public:
    virtual void display() const = 0;
    virtual double area() const = 0;
};

class Rectangle : public Figure
{
public:
    Rectangle(size_t length, size_t width):_length(length), _width(width){}
    void display() const { cout << "Rectangle"; }
    double area() const { return _length * _width; }
private:
    size_t _length;
    size_t _width;
};

class Circle : public Figure
{
public:
    Circle(double radius):_radius(radius){}
    void display() const { cout << "Circle"; }
    double area() const { return PI * _radius * _radius; }

private:
    double _radius;
};

void display(Figure & fig)
{
    fig.display();
    cout << "'s area is " << fig.area() << endl;
}

int main()
{
    Rectangle rectangle(3, 4);
    Circle circle(5);
    display(rectangle);
    display(circle);
    return 0;
}
