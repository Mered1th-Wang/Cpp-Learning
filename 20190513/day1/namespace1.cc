 ///
 /// @file    namespace1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-13 10:58:16
 ///
 
#include <stdio.h>
#include <iostream>
using namespace std;//using编译指令,会把空间中的所有实体一次性全部引入

namespace wd
{
int number = 10;//实体

void display()
{
	cout << "display()" << endl;
}

}//end of namespace wd
 
using namespace wd;

void cout()
{
	printf("hello,world\n");
}

int main(void)
{
	display();
	cout();

	return 0;
}
