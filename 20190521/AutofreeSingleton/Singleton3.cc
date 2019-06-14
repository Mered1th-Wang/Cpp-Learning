#include <stdlib.h>
#include <pthread.h>
#include <iostream>

using namespace std;

//atexit + pthread_once

class Singleton
{
public:
    static Singleton * getInstance()
    {
        pthread_once(&_once, init);
        return _pInstance;
    }
    
    void print() const
    {
        cout << "print()" << endl;
    }

    static void init()
    {
        _pInstance = new Singleton();
        atexit(destroy);
    }

    static void destroy()
    {
        if(_pInstance) delete _pInstance;
    }
private:
    Singleton() { cout << "Singleton()" << endl; }
    ~Singleton() { cout << "~Singleton()" << endl; }
    
private:
    static Singleton * _pInstance;
    static pthread_once_t _once;
};

Singleton * Singleton::_pInstance = nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main()
{
    Singleton * p = Singleton::getInstance();
    p->print();
    return 0;
}
