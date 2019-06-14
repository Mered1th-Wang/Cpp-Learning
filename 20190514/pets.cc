#include <cstring>
#include <iostream>

using namespace std;

class Pet
{
public:
    Pet(const char * name, float price);
    Pet(const Pet & rhs); 
    void print();
    ~Pet();
private:
    char * name;
    float price;
};

void Pet::print()
{
    cout << "name = " << this->name << endl
        << "price = " << this->price << endl;
    cout << "&name = " << &this->name << endl;
}
Pet::Pet(const char * name, float price):name(new char[strlen(name) + 1]()), price(price)
{
    strcpy(this->name, name);
    cout << "Pet(const char *, price)" << endl;
}

#if 0
//浅拷贝
Pet::Pet(const Pet & rhs):name(rhs.name), price(rhs.price)
{
    cout << "Pet (const Pet & rhs)" << endl;
}
#endif


#if 1
//深拷贝
Pet::Pet(const Pet & rhs):name(new char[strlen(rhs.name) + 1]()), price(rhs.price)
{
    strcpy(this->name, rhs.name);
    cout << "Pet (const Pet & rhs)" << endl;
}
#endif

Pet::~Pet()
{
    delete[] this->name;
    cout << "~Pet()" << endl;
}

int main(){
//    Pet dog("diandian", 2000);
//    dog.print();
    Pet cat("dudu", 5000);
    cat.print();
    Pet cat2(cat);
    cat2.print();
    
    return 0;
}
