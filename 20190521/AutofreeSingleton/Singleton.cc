#include <iostream>

using namespace std;

class Singleton
{
    class AutoRelease
    {
    public:
        AutoRelease()
        {
            cout << "AutoRelease()" << endl;
        }
        ~AutoRelease()
        {
            cout << "~AutoRelease()" << endl;
            if(_pInstance) delete _pInstance;
        }
    };
public:
    static Singleton * getInstance()
    {
        if(nullptr == _pInstance)
            _pInstance = new Singleton();
        return _pInstance;
    }
    void print() const 
    {
        cout << "print()" << endl;
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
    static AutoRelease _autoRelease;
};

Singleton * Singleton::_pInstance = nullptr;
Singleton::AutoRelease Singleton::_autoRelease;

int main()
{
    Singleton * p = Singleton::getInstance();
    p->print();

    return 0;
}
