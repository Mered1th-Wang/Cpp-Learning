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
		cout << _ix << "," << _iy << endl;
		cout << "Point(int,int)" << endl;
	}

	void print()
	{  
		cout << "(" << this->_ix
			 << "," << this->_iy 
			 << ")";
	}

	~Point()
	{	
		cout << "~Point()" << endl;	
	}

private:
	int _ix;
	int _iy;
};

class Line
{
public:
	//调用构造函数时，先执行初始化表达式，再执行函数执行体
	//
	//对于对象成员而言，也需要显式放在初始化表达式进行初始化
	//如果没有这个操作，就会调用相应类型的默认构造函数
	//
	Line(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1)
	, _pt2(x2, y2)
	{
		cout << "Line(int,int,int,int)" << endl;
	}

	void printLine() 
	{
		_pt1.print();
		cout << " ---> ";
		_pt2.print();
		cout << endl;
	}

private:
	Point _pt1;//自定义对象成员
	Point _pt2;//组合模式
};
 
int main(void)
{
	Line line(1, 2, 3, 4);
	line.printLine();

	return 0;
}
