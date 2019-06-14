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
		//_ix = ix;//error赋值语句
		//_iy = iy;
		cout << "Point(int,int)" << endl;
	}


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
	//const成员只能放到初始化表达式中进行初始化
	const int _ix;
	const int _iy;
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
	//pt = pt3 = pt2;//赋值语句   左操作数  右操作数
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
