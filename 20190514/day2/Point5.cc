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

	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
		//cout << this->_ix << endl;
		//cout << this->_iy << endl;
	}

	//运算符作用于自定义类类型
#if 1
	//返回值如果去掉&引用符号，return时会进行复制
	//void operator=(const Point & rhs)
	Point & operator=(const Point & rhs)
	{	//this指针代表的是左操作数
		this->_ix = rhs._ix;
		this->_iy = rhs._iy;
		return *this;
	}
#endif

	//隐含的this指针, 在编译时，编译器会自动加上
	void print()
	{   /*    Point * const this     */
		//this = 0x1000;//error
		cout << "(" << this->_ix
			 << "," << this->_iy 
			 << ")" << endl;
	}

	~Point()
	{	
		cout << "~Point()" << endl;	
	}

private:
	int _ix;
	int _iy;
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



int main(void)
{
	test0();
	return 0;
}
