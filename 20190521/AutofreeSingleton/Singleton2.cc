#include <stdlib.h>
#include <iostream>

using namespace std;

class Singleton
{
public:
    static Singleton * getInstance()
    {
        if(nullptr == _pInstance)
        {
            _pInstance = new Singleton;
            atexit(destroy);
        }
        return _pInstance;
    }
    static void destroy()
    {
        if(_pInstance) delete _pInstance;
    }
    void print() const
    {
        cout << "print()" << endl;
    }
private:
    Singleton() { cout << "Singleton()" << endl; }
    ~Singleton() { cout << "~Singleton()" << endl; }
private:
    static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = getInstance();

int main()
{
    Singleton *p = Singleton::getInstance();
    p->print();
    return 0;
}
