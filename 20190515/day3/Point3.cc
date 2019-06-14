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

	void show()
	{}


#if 1
	void print(/*    Point * const this    */) //非const成员函数
	{  
		cout << "void print()" << endl;
		_ix = 100;
		cout << "(" << this->_ix
			 << "," << this->_iy 
			 << ")" << endl;
	}
#endif

	//const成员函数的this指针两边都有const进行修饰
	//const成员函数内部不能修改数据成员，
	//不能调用非const成员函数
	//
	//一般情况下，如果某个成员函数没有修改成员，就应该设计成const的
#if 1
	void print(/*    const Point * const this     */) const
	{
		//show();//error
		//_ix = 1000;//error
		cout << "void print() const" << endl;
		cout << "(" << this->_ix
			 << "," << this->_iy 
			 << ")" << endl;
	}
#endif

	~Point()
	{	
		cout << "~Point()" << endl;	
	}

private:
	int _ix;
	int _iy;
};

void func(const Point & rhs)
{
	//rhs.print();
}

int main(void)
{
	Point pt(1, 2);//非const对象两者都可以调用
	pt.print();

	const Point pt2(3, 4);//const对象只能调用const成员函数
	pt2.print();
	return 0;
}
