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

	//析构函数 无返回值，无参数,只有一个
	//
	//作用：用来做清理工作的
	//
	//当对象的生命周期结束时，会自动调用析构函数
	//
	//如果不显式提供，系统也会自动提供一个析构函数
	~Point()
	{	
		//cout << "~Point()" << endl;	
	}

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

	cout << "sizeof(pt) = " << sizeof(pt) << endl;

	return 0;
}
