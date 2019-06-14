 ///
 /// @file    Empty.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-15 09:41:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Empty
{
public:
	//Empty(int) {}

};
 
int main(void)
{
	Empty e1;
	Empty e2;

	Empty e3(e1);

	e2 = e1;
	return 0;
}
