 ///
 /// @file    memory.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-14 10:17:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
int a = 10;// 位于全局静态区
char * p1;//nullptr
int main(void) //位于代码段 --> 只读
{
	int b;//不确定 栈上
	char s[] = "123456";
	char * p2;//不确定 栈上
	const char * p3 = "123456";// 文字常量区 -->只读
	//*p3 = '0';//error
	
	static int c = 0;//位于全局静态区

	p1 = new char[10]();
	p2 = new char[5]();

	printf("a = %d\n", a);
	printf("&a = %p\n", &a);
	printf("p1 = %p\n", p1);
	printf("&p1 = %p\n", &p1);
	printf("b = %d\n", b);
	printf("&b = %p\n", &b);
	printf("c = %d\n", c);
	printf("&c = %p\n", &c);
	printf("p2 = %p\n", p2);
	printf("&p2 = %p\n", &p2);
	printf("p3 = %p\n", p3);
	printf("&p3 = %p\n", &p3);

	printf("s = %p\n", s);//s+1 
	printf("&s = %p\n", &s);//&s + 1
	//s = 0x100;//常量, 不能修改

	printf("main = %p\n", main);


	return 0;
}
