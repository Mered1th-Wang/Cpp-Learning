 ///
 /// @file    typecast.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-13 15:51:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void test0()
{
	double number1 = 1.11;
	int number2 = (int)number1;
	int number3 = int(number1);

	cout << "number1 = " << number1 << endl;
	cout << "number2 = " << number2 << endl;
	cout << "number3 = " << number3 << endl;
}

void test1()
{
	double number1 = 1.11;
	int number2 = static_cast<int>(number1);
	cout << "number1 = " << number1 << endl;
	cout << "number2 = " << number2 << endl;

	int * pint = static_cast<int*>(malloc(sizeof(int)));
	*pint = 10;
	free(pint);
	
	//const_cast  去除常量属性
	//dynamic_cast  在基类与派生类之间
	//reinterpret_cast 在任意类型之间转换 持久化
}
 
int main(void)
{
	//test0();
	test1();
	return 0;
}
