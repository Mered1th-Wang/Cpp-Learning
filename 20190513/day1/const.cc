 ///
 /// @file    const.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-13 11:35:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//发生时机： 预处理, 简单的进行字符串替换, 没有类型检查
//注意: 使用宏定义可能会造成错误的概率要大于const关键字
#define NUMBER 100

void test0()
{
	//const修饰内置类型
	//发生时机: 编译时, 有类型检查，更安全
	const int number = 10;// 枚举类型也可以用来定义常量
	//number = 11;//error 常量不能进行修改
	
	//const int number2;//error 常量必须要进行初始化
}

//数组指针  vs  指针数组
//函数指针  vs  指针函数
//常量指针  vs  指针常量

void test1()
{
	//const关键字修饰指针
	int number = 100;
	int number2 = 1;
	const int * p = &number;// 常量指针(pointer to const)
	// *p = 10;//error  不能修改指针所指位置的变量的值
	p = &number2;//可以改变指针的指向

	int const * p2 = &number;
	//*p2 = 10;//error
	p2 = &number2;

	int * const p3 = &number;//指针常量(const pointer)
	*p3 = 11;//可以改变指针所指位置的变量的值
	//p3 = &number2;//error 不可以改变指向
	
	const int * const p4 = &number;//两者都不能进行修改
	//*p4 = 11;//error
	//p4 = &number2;//error
	
}

 
int main(void)
{
	test0();
	return 0;
}
