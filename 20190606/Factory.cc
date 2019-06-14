#include <cmath>
#include <iostream>
#include <memory>

using namespace std;

class Figure
{
public:
    virtual void display() const = 0;
    virtual double area() const = 0;
    virtual ~Figure() = default;
};


class Rectangle : public Figure
{
public:
    Rectangle(size_t length, size_t width)
        :_length(length), _width(width) {}

    virtual void display() const { cout << "Rectangle"; }
    virtual double area() const { return _length * _width; }
    virtual ~Rectangle() { cout << "~Rectangle()" << endl; }

private:
    size_t _length;
    size_t _width;
};

class Circle
: public Figure
{
public:
    Circle(double radius)
        : _radius(radius)
    {}

    void display() const
    {   cout << "Circle";   }

    double area() const
    {   return 3.14159 * _radius * _radius; }

    ~Circle() { cout << "~Circle()" << endl;    }

private:
    double _radius;

};

class Triangle
: public Figure
{
public:
    Triangle(size_t a, size_t b, size_t c)
        : _a(a)
          , _b(b)
          , _c(c)
    {}

    void display() const
    {   cout << "Triangle"; }

    double area() const
    {
        size_t p = (_a + _b + _c) / 2;
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));

    }

    ~Triangle() {   cout << "~Triangle()" << endl;  }   

private:
    size_t _a;
    size_t _b;
    size_t _c;
};


void display(Figure * fig)
{
    fig->display();
    cout << " 's area is " << fig->area() << endl;
}

class Factory
{
public:
    static Figure * createRectangle()
    {
        return new Rectangle(3, 4);
    }
    static Figure * createTriangle()
    {
        return new Triangle(3, 4, 5);
    }
    static Figure * createCircle()
    {
        return new Circle(10);
    }
};

int main()
{
    unique_ptr<Figure> rectangle(Factory::createRectangle());
    unique_ptr<Figure> triangle(Factory::createTriangle());
    unique_ptr<Figure> circle(Factory::createCircle());

    display(rectangle.get());
    display(triangle.get());
    display(circle.get());

    return 0;
}
