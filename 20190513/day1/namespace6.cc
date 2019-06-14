 ///
 /// @file    namespace5.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-13 11:21:02
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int number = 1;

namespace wd
{
int number = 10;

void display(int number)
{
	cout << "wd::display()" << endl;
	cout << "number = " << number << endl;//就近原则
	cout << "wd::number = " << wd::number << endl;
	cout << "全局number = " << ::number << endl;//匿名命名空间
	::printf("hello,world\n");
}

}//end of namespace wd
 
int main(void)
{
	int x = 100;
	wd::display(x);

	return 0;
}
