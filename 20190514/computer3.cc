#include <cstring>

#include <iostream>

using namespace std;

class Computer
{
public:
    Computer(const char * brand, float price)
        :_brand(new char[strlen(brand) + 1]()), _price(price)
    {
        strcpy(_brand, brand);
        cout << "Computer(const char *, float)" << endl;
    }
    
    void print();
    
    void release(){
        delete [] _brand;
    }

    ~Computer()
    {
        cout << "~Computer()" << endl;
    }
private:
    char* _brand;
    int _price;
};

Computer pc3("Dell", 7777);


int test(){
    Computer pc1("lele", 11111);
    pc1.print();
    pc1.release();

    cout << "sizeof(Computer) = " << sizeof(Computer) << endl
        << "sizeof(pc1) = " << sizeof(pc1) << endl;

    Computer * pc2 = new Computer("Thinkpad", 8888);
    pc2->print();

    delete pc2;
    cout << endl;

    pc3.print();
    cout << endl;

    static Computer pc4("Xiaomi", 7500);
    pc4.print();

    return 0;
}

void Computer::print(){
    cout << "brand:" << this->_brand << endl
        << "price:" << this->_price << endl;
}

int main(){
    test();
    return 0;
}
