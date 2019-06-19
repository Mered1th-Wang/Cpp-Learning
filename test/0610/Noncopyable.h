#pragma once//作用是什么？

#include<stdio.h>
#include<iostream>
//#include<stdio.h>
//#pragma once

//为什么要用namespace？
//c++11的新标准：delete掉拷贝构造函数和赋值运算符函数
namespace wd
{
class Noncopyable
{
protected:
	Noncopyable(){}

	~Noncopyable(){}

	Noncopyable (const Noncopyable & )=delete;
	Noncopyable & operator=(const Noncopyable &)=delete;
};
}//end of wd
