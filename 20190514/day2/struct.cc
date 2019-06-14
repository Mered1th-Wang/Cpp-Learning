 ///
 /// @file    struct.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-14 11:48:08
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
 
//C++对struct做了扩展
struct Computer  // 更常用的方式是作为函数对象出现
{//struct的默认访问权限是public
//public:
	void setBrand(const char * brand);
	void setPrice(float price);
	void print();

//private:
	char _brand[20];
	float _price;
};

void Computer::setBrand(const char * brand)
{
	strcpy(_brand, brand);
}

void Computer::setPrice(float price)
{
	_price = price;
}

void Computer::print()
{
	cout << "brand: " << _brand << endl
		 << "price: " << _price << endl;
}

int main(void)
{
	//struct Computer pc;
	Computer pc;
	pc.setBrand("Lenovo");
	pc.setPrice(5555);
	pc._price = 10000;
	pc.print();

	return 0;
}
