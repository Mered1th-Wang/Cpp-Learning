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
	
	//复制构造函数和赋值运算符函数统一称为复制控制函数

	//复制构造函数
	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1]())//深拷贝
	, _price(rhs._price)
	{
		cout << "Computer(const Computer&)" << endl;
		strcpy(_brand, rhs._brand);
	}

#if 0
	//系统提供的不满足需求
	Computer & operator=(const Computer & rhs)
	{
		_brand = rhs._brand;
		_price = rhs._price;
		return *this;
	}
#endif
	//赋值运算符函数
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

	~Computer()
	{	
		delete [] _brand;
		cout << "~Computer()" << endl;
	}

private:
	char * _brand;
	float _price;
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
	Computer pc2 = pc1;//在该语句之前，pc2不存在,构造对象的过程
	//Computer pc2(pc1);// 等价
	cout << "pc2: --> " << endl;
	pc2.print();
	return 0;
}

void test1()
{
	Computer pc1("Xiaomi", 7500);
	cout << "pc1: --> " << endl;
	pc1.print();

	Computer pc2("Thinkpad", 8800);
	cout << "pc2: --> " << endl;
	pc2.print();

	pc2 = pc1;//简写，调用的是赋值运算符函数
	//pc2.operator=(pc1);
	cout << endl << "执行pc2 = pc1之后:" << endl;
	cout << "pc2: --> " << endl;
	pc2.print();

	pc2 = pc2;//自复制

	int a = 3;
	a = a;
}


int main(void)
{
	//test0();
	test1();
	return 0;
}
