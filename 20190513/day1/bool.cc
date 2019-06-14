 ///
 /// @file    bool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-13 16:42:12
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	//_Bool c1 = 1;//c99标准

	bool b1 = 10;
	bool b2 = 1;
	bool b3 = -1;
	bool b4 = 0;
	bool b5 = true;
	bool b6 = false;
	cout << "sizeof(bool) = " << sizeof(bool) << endl;
	cout << "b1 = " << b1 << endl;
	cout << "b2 = " << b2 << endl;
	cout << "b3 = " << b3 << endl;
	cout << "b4 = " << b4 << endl;
	cout << "b5 = " << b5 << endl;
	cout << "b6 = " << b6 << endl;

	return 0;
}
