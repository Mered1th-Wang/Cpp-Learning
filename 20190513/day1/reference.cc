 ///
 /// @file    reference.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-13 14:46:13
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void test0()
{
	int number = 1;	
	int & ref = number;//引用称为变量的别名
	//一经初始化之后，就不会再改变指向
	//
	//引用底层实现还是指针
	//
	cout << "ref = " << ref << endl
		 << "number = " << number << endl;

	ref = 2;
	cout << "ref = " << ref << endl
		 << "number = " << number << endl;

	number = 3;
	cout << "ref = " << ref << endl
		 << "number = " << number << endl;

	int number2 = 10;
	ref = number2;//赋值语句

	cout << "ref = " << ref << endl
		 << "number = " << number << endl;
	cout << "&ref = " << &ref << endl
		 << "&number = " << &number << endl
		 << "&number2 = " << &number2 << endl;

	//int & ref2;//error  引用不能单独存在的, 必须进行初始化
	int * p;//野指针
	//*p = 10;//error
}



//值传递 ==> 进行复制
//void swap(int x, int y)
//{
//	int temp = x;
//	x = y;
//	y = temp;
//}

//地址传递 ==> 值传递 => 进行复制
void swap(int * px, int * py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}

//1. 引用作为函数的参数进行传递
//
//引用传递的执行效率更高，没有复制的开销
//在形式上更直观，容易理解
void swap(int & x, int & y)
{
	int temp = x;
	x = y;
	y = temp;
}

void test1()
{
	int a = 3, b = 4;
	cout << "a = " << a << ", b = " << b << endl;
	swap(a, b);
	//swap(&a, &b);
	cout << "a = " << a << ", b = " << b << endl;
}

//2. 引用还可以作为函数的返回值

int array[5] = {0, 1, 2, 3, 4};//全局/静态区

//当执行return语句时，都会进行复制
int func()
{
	int number = 10;//栈区
	return number;
}

//当执行return语句时，不会进行复制
//条件: 返回的引用所对应的变量，生命周期一定要大于函数的
int & index(int idx)
{
	return array[idx];
}

//引用作为返回值时，不能返回局部变量的引用
int & func1()
{
	int number = 10;//栈区
	return number;
}

//引用作为返回值，如果返回是一个堆空间的数据，
//一般不要轻易返回堆空间的数据，有可能会导致内存泄漏
//除非已经有了内存回收的策略，才去返回堆空间的变量的引用
int & func2()
{
	int * pint = new int(10);
	return *pint;
}


void test2()
{
	index(0) = 10;
	cout << "array[0] = " << array[0] << endl;

	//int & ref = func1();//
	//cout << "ref = " << ref << endl;//error 
	
	int & ref2 = func2();
	cout << "ref2 = " << ref2 << endl;
	delete &ref2;

	int a = 3, b = 4;
	int c = a + func2() + b;
	cout << "c = " << c << endl;
}
 
int main(void)
{
	//test0();
	//test1();
	test2();

	return 0;
}
