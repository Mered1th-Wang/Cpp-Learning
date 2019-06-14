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
	
	void print();

#if 0
	//系统提供的析构函数已经不能满足需求了
	~Computer()
	{}

#endif
	void release()
	{
		delete [] _brand;
	}

	~Computer()
	{	//做清理工作
		release();
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
	cout << "brand: " << _brand << endl
		 << "price: " << _price << endl;
}

//全局对象是在main退出之后，才调用了析构函数
Computer pc3("Dell", 7777);


int test0(void)
{
	//栈对象同时要求构造函数和析构函数都是public
	Computer pc1("Lenovo", 5555);
	pc1.print();
	pc1.release();
	//pc1.~Computer();//析构函数也可以显式调用，但一般情况下
					//不建议这样做

	cout << "sizeof(Computer) = " << sizeof(Computer) << endl
		 << "sizeof(pc1) = " << sizeof(pc1) << endl << endl;


	//堆对象, 执行new表达式时，要调用构造函数
	Computer * pc2 = new Computer("Thinkpad", 8888);
	pc2->print();

	delete pc2;//执行delete表达式时,要调用析构函数
	cout << endl;

	pc3.print();

	cout << endl;
	//静态对象在main函数退出之后，会调用析构函数
	static Computer pc4("Xiaomi", 7500);
	pc4.print();

	return 0;
}

int main(void)
{
	test0();
	cout << "......." << endl;
	return 0;
}
