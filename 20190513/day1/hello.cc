 ///
 /// @file    hello.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-13 10:20:16
 ///

//#include "head.h"  //自定义头文件放在最上面的位置

#include <stdio.h>	//c标准库头文件

#include <iostream> //c++标准头文件, 内部实现是模板

using namespace std;//命名空间
 
int main(int argc, char ** argv)
{
	printf("hello,world\n");
	cout << "hello,world!" << endl;//cout是输出流对象, 输出流运算符
	return 0;
}
