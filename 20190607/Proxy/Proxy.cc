#include <string>
#include <iostream>

using namespace std;

class Subject
{
public:
    virtual void Request() = 0;
};

class RealSubject : public Subject
{
public:
    virtual void Request() 
    {
        cout << "RealSubject.Request()" << endl;
    }
};

class Proxy : public Subject
{
public:
    virtual void Request()
    {
        realSubject = new RealSubject();
        realSubject->Request();
        delete realSubject;
    }
private:
    RealSubject * realSubject;
};

int main()
{
    Proxy * test = new Proxy();
    test->Request();
    return 0;
}
