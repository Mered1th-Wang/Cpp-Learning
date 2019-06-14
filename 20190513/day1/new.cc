 ///
 /// @file    new.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-13 14:31:43
 ///
 
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

void test0()
{
	int * pint = (int *)malloc(sizeof(int));
	*pint = 10;
	cout << "*pint = " << *pint << endl;

	free(pint);
}

// malloc/free与new/delete表达式的区别?
// 答: malloc/free是C中的库函数, malloc只负责申请空间; calloc
//     new/delete是表达式, new表达式除了申请空间外，还可以
//     进行初始化

void test1()
{
	int * pint = new int(10);
	cout << "*pint = " << *pint << endl;

	delete pint;

	//对于数组型的，要带上[]
	int * parray = new int[10]();
	for(int idx = 0; idx != 10; ++idx) {
		cout << parray[idx] << " ";
	}
	cout << endl;

	delete [] parray;
}
 
int main(void)
{
	//test0();
	test1();
	return 0;
}
