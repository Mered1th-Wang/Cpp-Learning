 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-14 14:33:14
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//当没有显式定义构造函数时，系统会自动提供一个
	//默认(无参)构造函数
#if 0
	Point()
	{
		cout << "Point()" << endl;
		_ix = 0;
		_iy = 0;
	}
#endif

	//构造函数可以进行重载
	//有参构造函数
	//
	//一旦显式定义了有参构造函数之后，系统就不会再
	//提供默认(无参)构造函数
	//
	//数据成员的初始化是在初始化表达式中进行的
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy 
			 << ")" << endl;
	}

#if 0
	void setX(int ix)
	{	_ix = ix;	}

	void setY(int iy)
	{	_iy = iy;	}
#endif
private:
	int _ix;
	int _iy;
};
 
int main(void)
{
	int number(1);
	Point pt;//当创建对象时，构造函数会自动调用
	pt.print();
	Point pt2(1, 2);
	pt2.print();

	return 0;
}
