#include <cstring>

#include <iostream>

using namespace std;

class Computer
{
public:
    void setBrand(const char * brand);
    void setPrice(const int price);
    void print();
private:
    char* _brand;
    int _price;
};

int main(){
    Computer pc;
    pc.setBrand("magic");
    pc.setPrice(4999);
    pc.print();
    return 0;
}

void Computer::setBrand(const char * brand){
    //  delete [] this->_brand;
    this->_brand = new char[strlen(brand) + 1]();
    strcpy(this->_brand, brand);
}
void Computer::setPrice(const int price){
    this->_price = price;
}
void Computer::print(){
    cout << "brand:" << this->_brand << endl
        << "price:" << this->_price << endl;
}
