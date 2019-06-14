 ///
 /// @file    X.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-14 14:48:55
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class X
{
public:
	//数据成员的初始化，与其在初始化列中的顺序无关，
	//只与其在类中被声明时的顺序有关
	X(int x)
	: _iy(x)
	, _ix(_iy)
	{
		cout << "X(int)" << endl;
	}

	void print()
	{
		cout << "_ix = " << _ix << ","
			 << "_iy = " << _iy << endl;
	}


private:
	int _ix;
	int _iy;
};
 
int main(void)
{
	X x(10);
	x.print();

	return 0;
}
