 ///
 /// @file    namespace1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-13 10:58:16
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;//using声明机制, 推荐使用
using std::endl;


namespace wd
{
void print();//函数声明
void show()
{
	cout << "wd::show()" << endl;
}
}//end of namespace wd


namespace tls
{

void display()
{
	//printf("hello,world\n");
	cout << "display()" << endl;
}

void print()
{
	cout << "tls::print()" << endl;
	wd::print();
}

}//end of namespace tls

namespace wd
{
int number = 10;//实体

void display()
{
	cout << "wd::display()" << endl;
	tls::print();
}

void print() //函数实现
{
	cout << "wd::print()" << endl;
}

}//end of namespace wd
 

int main(void)
{
	wd::display();
	wd::show();

	return 0;
}
