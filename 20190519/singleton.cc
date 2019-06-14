#include <iostream>

using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "Singleton" << endl;
    }
    ~Singleton()
    {
        cout << "~Singleton" << endl;
    }

private:
    static Singleton* _pInstance;

public:
    static Singleton * getInstance()
    {
        if(nullptr == _pInstance)
        {
            _pInstance = new Singleton;
        }
        return _pInstance;
    }
    static void destroy()
    {
        if(_pInstance)
        {
            delete _pInstance;
        }
    }
    void print() const
    {
        cout << "Singleton::print()" << endl;
    }
};

Singleton* Singleton::_pInstance = nullptr;

int main()
{
    Singleton * p1 = Singleton::getInstance();
    Singleton * p2 = Singleton::getInstance();

    p1->print();
    p2->print();
    Singleton::getInstance()->print();
    Singleton::destroy();

    return 0;
}
