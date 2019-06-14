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
int number = 10;//实体

void display()
{
	cout << "wd::display()" << endl;
}

}//end of namespace wd
 

//void cout()
void display()
{
	//printf("hello,world\n");
	cout << "display()" << endl;
}

int main(void)
{
	//using namespace wd;
	//display();
	//wd::display();
	using wd::display;//起作用的位置就在该函数内部
	display();

	return 0;
}
