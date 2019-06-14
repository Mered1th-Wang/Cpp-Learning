 ///
 /// @file    default.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-13 16:32:01
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//一旦将函数参数之中某一个参数设置默认参数之后， 
//其后的所有参数都必须设置默认参数
//
//作用：少写代码
int add(int x = 0, int y = 0) 
{
	return x + y;
}

//在使用默认(缺省)参数时，要注意不要产生二义性
//int add(int x, int y, int z = 0)
int add(int x, int y, int z)
{
	return x + y + z;
}


//如果将一个函数的声明与实现分开，只需要在
//声明中设置默认参数即可，实现中就不再需要了
int sub(int x = 0, int y = 0);

int main(void)
{
	int a = 3, b = 4, c = 5;
	cout << "add() = " << add() << endl;
	cout << "add(a) = " << add(a) << endl;
	cout << "add(a, b) = " << add(a, b) << endl;

	cout << "sub(a, b) = " << sub(a, b) << endl;
 
	return 0;
}

int sub(int x, int y)
{
	return x - y;
}
