#pragma once
//#pragma once in main file”
//#pragma once 出现在主文件中”
//#include<iostream>
//#include<stdio.h>
#include<queue>
//#include"Noncopyable.h"
//#include"MutexLock.h"
#include"Condition.h"

using namespace std;
//千万别重复定义头文件，mutex中已经由lock和condition了！！注意注意!
namespace wd
{
class TaskQueue
:Noncopyable
{
private:
	size_t _quesize;
	queue<int>_que;
	MutexLock _mutex;//这个到底有什么用啊？
	Condition _notfull;
	Condition _notempty;

public:
	TaskQueue( size_t  quesize=10)//size_t & quesize=10 这个是右值貌似不能用& 引用
	:_quesize(quesize)
 	,_que()
	,_mutex()
 	,_notfull(_mutex)
	,_notempty(_mutex)	
	{}

	~TaskQueue(){}

	void push(const int number);
	int pop();
	bool full()const;
	bool empty()const;

};

}//end of wd
