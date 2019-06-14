#include <iostream>

using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "构造函数调用" << endl; 
    }
    ~Singleton()
    {
        cout << "析构函数调用" << endl;
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
        if(_pInstance)
        {
            cout << "Singleton::print()" << endl;
        }
    }
};

Singleton* Singleton::_pInstance = nullptr;

int main(){
    Singleton * p1 = Singleton::getInstance();
    Singleton * p2 = Singleton::getInstance();
    cout << p1 << endl << p2 << endl;

    Singleton::getInstance()->print();

    Singleton::destroy();

    return 0;
}
