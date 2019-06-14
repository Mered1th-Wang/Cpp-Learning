#include <iostream>

using namespace std;

class Animal
{
public:
    int _age;
};

class Sheep: virtual public Animal
{

};

class Tuo: virtual public Animal
{

};

class SheepTuo: public Sheep, public Tuo
{

};

int main()
{
    SheepTuo test;
    cout << "size = " << sizeof(test) << endl;
    test.Sheep::_age = 10;
    test.Tuo::_age = 20;

    cout << test._age << endl;

    return 0;
}
