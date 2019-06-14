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

	//复制(拷贝)构造函数
	//系统提供的
	//
	//复制构造函数的形式可不可以修改:
	//1. 引用&符号可以去掉不? 不可以，如果去掉，会
	//   陷入自身的无穷递归，直到栈溢出, 程序崩溃
	//
	//2. const可以去掉不? 不可以，因为非const的左值引用
	//   无法绑定到右值(无法取地址的对象), 只有const引用
	//   可以绑定到右值
	//
	//   去掉const之后，如果传递过来的是一个右值，无法传参
	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy 
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

	Point pt(1, 2);
	cout << "pt = ";
	pt.print();
	Point pt2 = pt;//创建对象pt2
	//Point(const Point rhs);//const Point rhs = pt;
	//Point(const Point rhs);//const Point rhs = pt;
	//Point(const Point rhs);//const Point rhs = pt;
	//...
	cout << "pt2 = ";
	pt2.print();

	return 0;
}

//值传递 ==》进行复制
//调用复制构造函数
void func(Point pt)
{
	pt.print();
}

void test1()
{
	Point p(11, 12);
	func(p);
}

//函数的返回值是对象，执行return语句时，会调用复制构造函数
Point getPoint()
{
	Point pt(11,12);
	pt.print();
	return pt;
}

void test2()
{
	int number = 1;
	int & ref =  number;//非const的左值引用只能绑定到左值
						//不能绑定到右值
	//int & ref2 = 1;//字面值无法取地址
	//&1;//右值
	const int & ref3 = 1;//const引用可以绑定到右值

	//&getPoint();//临时对象, 匿名对象=> 右值 ==> 无法持久化的对象
	Point pt = getPoint();
	&pt;

}

void test3()
{
	Point(1, 2).print();

	cout << "...." << endl;
}

int main(void)
{
	//test1();
	//test2();

	test3();
	return 0;
}
