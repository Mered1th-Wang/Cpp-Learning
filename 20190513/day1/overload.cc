 ///
 /// @file    overload.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-13 16:02:48
 ///

#include <stdio.h>
 
#include <iostream>
using std::cout;
using std::endl;


//C++支持函数重载
//实现原理: 名字改编(name mangling)
//操作步骤: 
//	  当函数名称相同时，根据函数参数的类型、顺序、个数进行改编
//
//进行了改编的函数，是按C++方式进行调用 1983
//
//不进行名字改编，是按C方式进行调用  1972
//
//在现实编程时，会出现C与C++的混合编程的情况
//


//如果写的是c的代码，希望它能同时在C和C++编译环境下
//都能正常使用
#ifdef __cplusplus
extern "C" 
{
#endif

int add(int x, int y)
{
	return x + y;
}

#ifdef __cplusplus
}// end of extern "C"
#endif

double add(double x, double y)
{
	return x + y;
}

double add(int x, double y)
{
	return x + y;
}

double add(double x, int y)
{
	return x + y;
}

int add(int x, int y, int z)
{
	return x + y + z;
}
 
int main(void)
{
	int a = 3, b = 4, c = 5;
	double d1 = 1.11, d2 = 2.22;
	printf("a + b = %d\n", add(a, b));
	cout << "add(a, b, c) = " << add(a, b, c) << endl;
	cout << "add(d1, d2) = " << add(d1, d2) << endl;
	cout << "add(d1, a) = " << add(d1, a) << endl;
	cout << "add(a, d1) = " << add(a, d1) << endl;
	return 0;
}
