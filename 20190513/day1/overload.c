 ///
 /// @file    overload.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-13 16:03:07
 ///
 
#include <stdio.h>

//C语言并不支持函数重载
//函数名必须是唯一
int add(int x, int y)
{
	return x + y;
}

int add2(int x, int y, int z)
{
	return x + y + z;
}
 
int main(void)
{
	int a = 3, b = 4;
	printf("a + b = %d\n", add(a, b));
	return 0;
}
