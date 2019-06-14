#include <iostream>
#include <memory>

using namespace std;

class Parent;
class Child
{
public:
    Child() { cout << "Child()" << endl; }
    ~Child() { cout << "~Child()" << endl; }

    shared_ptr<Parent> _pParent;
};

class Parent
{
public:
    Parent() { cout << "Parent()" << endl; }
    ~Parent() { cout << "~Parent()" << endl; }

    shared_ptr<Child> _pChild;
};

int main()
{
    shared_ptr<Parent> pParent(new Parent());
    shared_ptr<Child> pChild(new Child);

    cout << "pParent's use_count = " << pParent.use_count() << endl;
    cout << "pChild's use_count = " << pChild.use_count() << endl;

    pParent->_pChild = pChild;
    pChild->_pParent = pParent;

    cout << "pParent's use_count = " << pParent.use_count() << endl;
    cout << "pChild's use_count = " << pChild.use_count() << endl;
    
    return 0;
}
