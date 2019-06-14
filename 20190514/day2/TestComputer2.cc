 ///
 /// @file    TestComputer2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-14 11:44:34
 ///
 
#include "Computer2.h"
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	Computer pc;
	pc.setBrand("Lenovo");
	pc.setPrice(5555);
	pc.print();
	return 0;
}
