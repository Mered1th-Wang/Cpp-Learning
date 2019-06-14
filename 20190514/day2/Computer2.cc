 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-14 11:12:28
 ///
 
#include "Computer2.h"
#include <string.h>

#include <iostream> 
using std::cout;
using std::endl;
 
//虽然位置是在类之外实现成员函数
//但是一样可以访问私有成员
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
