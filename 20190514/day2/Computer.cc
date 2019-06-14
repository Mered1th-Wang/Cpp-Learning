 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-14 11:12:28
 ///
 
#include <string.h>

#include <iostream> //标准库中的类型都是小写的
using std::cout;
using std::endl;

//规定:		
//  > 自定义类类型的名字要大写首字母
//  > 数据成员(private)要放在类的尾部
//  > 在类的头部位置定义成员函数(public), 表示该类能够完成的功能
//  > 数据成员的第一个字符加上 "下划线"
//  > 成员函数的名字采用驼峰的形式命名, 第一个字母用小写，其他的用大写
//
//	> 目标: 代码的可读性 --> 有一个良好的代码风格
//		> code review  --> 人工代码走查
//					   --> 代码走查软件 --> 代码静态分析
//
class Computer
{//大括号所在的范围称为类内部，其他的地方称为类之外
public://该类提供的接口、功能、服务
//public成员可以在类之外直接访问
	void setBrand(const char * brand)
	{//实现了成员函数
		strcpy(_brand, brand);
	}

	void setPrice(float price)// 成员函数
	{
		_price = price;
	}

	void print()
	{
		cout << "brand: " << _brand << endl
			 << "price: " << _price << endl;
	}

private://体现封装的特性
//private的成员不能在类之外直接访问
	char _brand[20];// brand_ / m_brand
	float _price;//数据成员
};
 
int main(void)
{
	//int number;
	Computer pc;
	pc.setBrand("Lenovo");
	pc.setPrice(5555);
	pc.print();

	//pc._price = 5555;//error 
 
	return 0;
}
