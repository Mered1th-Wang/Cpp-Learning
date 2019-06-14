 ///
 /// @file    Computer2.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-14 11:43:21
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
 
class Computer
{
public:
	Computer(const char * brand, double price);
	
	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1]())//深拷贝
	, _price(rhs._price)
	{
		cout << "Computer(const Computer&)" << endl;
		strcpy(_brand, rhs._brand);
	}

	Computer & operator=(const Computer & rhs)
	{
		cout << "Computer & operator=(const Computer &)" << endl;
		if(this != &rhs) {//自复制
			delete [] _brand;//回收左操作数开辟的空间

			//进行深拷贝
			_brand = new char[strlen(rhs._brand) + 1]();
			strcpy(_brand, rhs._brand);

			_price = rhs._price;
		}
		return *this;
	}
	
	void print();

	//静态成员函数是特殊的成员函数，没有隐含的this指针了
	static void printTotalPrice();

	~Computer()
	{	
		delete [] _brand;
		cout << "~Computer()" << endl;
		_totalPrice -= _price;
	}

private:
	char * _brand;
	double _price;
	//静态数据成员是被整个类所共享的
	static double _totalPrice;//放在全局静态区
};

//静态成员的初始化要放在类之外进行
double Computer::_totalPrice = 0;//全局位置

Computer::Computer(const char * brand, double price)
: _brand(new char[strlen(brand) + 1]())
, _price(price)
{
	cout << "Computer(const char *, float)" << endl;
	strcpy(_brand, brand);
	_totalPrice += _price;
}

void Computer::print()
{
	//printf(">> _brand: %p\n", _brand);
	cout << " >> brand: " << this->_brand << endl
		 << " >> price: " << this->_price << endl;
}


void Computer::printTotalPrice()
{	//静态成员函数内部不能直接访问非静态的成员
	//只能访问静态成员
	//print();
	//cout << " >> brand: " << this->_brand << endl
	//	 << " >> price: " << this->_price << endl;
	cout << " >> totalPirce : " << _totalPrice << endl;
}


int test0(void)
{
	cout << "sizeof(Computer) = " << sizeof(Computer) << endl;
	Computer pc1("Xiaomi", 7500);
	cout << "pc1: --> " << endl;
	pc1.print();//Computer::print(&pc1);
	//pc1.printTotalPrice();//Computer::printTotalPrice();
	Computer::printTotalPrice();//静态成员函数一般直接通过类名调用
	cout << endl;

	Computer pc2("Thinkpad", 8888);
	cout << "pc2: --> " << endl;
	pc2.print();
	//pc2.printTotalPrice();
	Computer::printTotalPrice();

	//cout <<	Computer::_totalPrice  << endl;

	return 0;
}


int main(void)
{
	test0();
	return 0;
}
