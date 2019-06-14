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
	Computer(const char * brand, float price);

	//系统提供的复制构造函数
#if 0
	Computer(const Computer & rhs)
	: _brand(rhs._brand)  //浅拷贝
	, _price(rhs._price)
	{
		cout << "Computer(const Computer&)" << endl;
	}
#endif
	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1]())//深拷贝
	, _price(rhs._price)
	{
		cout << "Computer(const Computer&)" << endl;
		strcpy(_brand, rhs._brand);
	}
	
	void print();

	~Computer()
	{	//做清理工作
		delete [] _brand;
		cout << "~Computer()" << endl;
	}

private:
	char * _brand;
	float _price;//字节对齐, 有4个字节的空间被浪费了
};

Computer::Computer(const char * brand, float price)
: _brand(new char[strlen(brand) + 1]())
, _price(price)
{
	cout << "Computer(const char *, float)" << endl;
	strcpy(_brand, brand);
}

void Computer::print()
{
	printf(">> _brand: %p\n", _brand);
	cout << " >> brand: " << _brand << endl
		 << " >> price: " << _price << endl;
}


int test0(void)
{
	Computer pc1("Xiaomi", 7500);
	cout << "pc1: --> " << endl;
	pc1.print();

	//当把一个已经存在的对象赋值给新对象
	Computer pc2 = pc1;
	//Computer pc3(pc1);// 等价
	cout << "pc2: --> " << endl;
	pc2.print();
	return 0;
}


int main(void)
{
	test0();
	return 0;
}
