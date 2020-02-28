#include "TaskQueue.h"
#include <iostream>
using namespace std;

namespace wd
{
             
bool TaskQueue::full() const
{
	return _que.size() == _queSize;
}

bool TaskQueue::empty() const
{
	return _que.empty();
}

//push方法运行在生产者线程
void TaskQueue::push(int number)
{
	{
	MutexLockGuard autolock(_mutex);
	while(full()) {
		_notFull.wait();//使用while是为了防止异常唤醒
	}

	_que.push(number);
	}// 使用语句块减小加锁的范围
	_notEmpty.notify();

}

//pop方法运行在消费者线程
int TaskQueue::pop()
{
	int ret;
	{
	MutexLockGuard autolock(_mutex);
	while(empty()) {
		_notEmpty.wait();
	}

	ret = _que.front();
	_que.pop();
	}
	_notFull.notify();

	return ret;
}

}//end of namespace wd
 
