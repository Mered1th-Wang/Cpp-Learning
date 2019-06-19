#include"TaskQueue.h"
#include<iostream>
using namespace std;

namespace wd
{
	void TaskQueue::push( int number)
	{	
		MutexGuard autolock(_mutex);
		while(full())
		{
			_notfull.wait();//会在阻塞之前自动解锁？
		}
			_que.push(number);
			_notempty.notify();//会在解除阻塞之前自动加锁?
		

	}

	int TaskQueue::pop()
	{	
		MutexGuard autolock(_mutex);//到底是怎样给他加锁的
		while(empty())
		{
			_notempty.wait();
		}
		int ret=_que.front();
		_que.pop();
		_notfull.notify();
		return ret;

	}

	bool TaskQueue::full()const
	{
		return _que.size()==_quesize;
	}	

	bool TaskQueue::empty()const
	{
		return _que.empty();
	}
} // end of wd;
