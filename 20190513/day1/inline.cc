 ///
 /// @file    inline.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-13 16:46:56
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

//直接使用带参数的宏定义,犯错误的概率很大
#define max(x,y) (x>y?x:y)
#define multiply(x,y) ((x)*(y))  

//inline函数在功能上来说，是一样的, 在使用时，会用函数执行体内
//的语句进行替换
//inline函数还是需要类型检查, 相比带参数的宏定义安全性更高
//
//推荐使用inline函数
//
//对于某些现代编译器，会自动判断一个函数是否为inline函数
//
//inline函数内部不要写循环语句
//
inline
int getMax(int x, int y)
{	return x > y ? x : y;	}	

inline
int getMultiply(int x, int y)
{	return x * y;	}

 
int main(void)
{
	int a = 1, b = 2, c = 3;
	cout << "max(x, y) = " << max(a, b) << endl;
	cout << "getMax(x, y) = " << getMax(a, b) << endl;
	//printf("max(a, b) = %d\n", max(a, b));

	cout << "multiply(a + b, c) = " << multiply(a + b, c) << endl; 
	cout << "getMultiply(a + b, c) = " << getMultiply(a + b, c) << endl; 


	return 0;
}
