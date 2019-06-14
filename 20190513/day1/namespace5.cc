 ///
 /// @file    namespace5.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-13 11:21:02
 ///
 
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
int number = 10;

void display()
{
	cout << "wd::display()" << endl;
}

namespace lwh
{

void display()
{
	cout << "wd::lwh::display()" << endl;
}

}//end of namespace lwh

}//end of namespace wd
 
int main(void)
{
	wd::display();
	wd::lwh::display();

	return 0;
}
