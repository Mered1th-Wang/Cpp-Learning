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
	//在类内部实现的函数都是inline函数
	Point() = default;

	explicit //要求显式调用构造函数, 禁止隐式转换
	Point(int ix, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	//委托构造函数
#if 0
	Point(int ix)
	: Point(ix, 0)
	{
		cout << "Point(int)" << endl;
	}
#endif

	void print()
	{  
		cout << "(" << this->_ix
			 << "," << this->_iy 
			 << ")" << endl;
	}

	~Point()
	{	
		cout << "~Point()" << endl;	
	}

private:
	int _ix = 10;
	int _iy = 10;
	//....
};
 
int test0(void)
{
	int a = 3;
	int b = a;
	cout << "a = " << a << ", b = " << b << endl;
	int c = 4;
	c = a = b;//赋值语句


	Point pt(1, 2);
	cout << "pt = ";
	pt.print();//pt.print(&pt);
			   //Point::print(&pt);
	Point pt2 = pt;//创建对象pt2
	cout << "pt2 = ";
	pt2.print();
	cout << endl;

	Point pt3(11, 12);
	cout << "pt3 = ";
	pt3.print();//Point::print(&pt3);
	cout << ">> 执行pt = pt3之后:" << endl;
	pt = pt3 = pt2;//赋值语句   左操作数  右操作数
	//pt.operator=(pt3); //完整形式
	cout << "pt = ";
	pt.print();

	Point * pt4 = new Point(21, 22);
	pt4->print();//Point::print(pt4);

	return 0;
}

void test1()
{
	Point pt(1);
	pt.print();

	Point pt2;
	pt2.print();
}

void test2()
{
	//Point = int;
	//Point pt = 5;//存在隐式转换  Point(5) 临时对象
	//pt.print();
}


int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}
