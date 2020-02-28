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
void TaskQueue::push(const ElemType & elem)
{
	{
	MutexLockGuard autolock(_mutex);
	while(full()) {
		_notFull.wait();//使用while是为了防止异常唤醒
	}

	_que.push(elem);
	}// 使用语句块减小加锁的范围
	_notEmpty.notify();

}

//pop方法运行在消费者线程
ElemType TaskQueue::pop()
{
	MutexLockGuard autolock(_mutex);
	while(_flag && empty()) {
		_notEmpty.wait();
	}

	if(_flag) {
		ElemType ret = _que.front();
		_que.pop();
		_notFull.notify();
		return ret;
	} else {
		return ElemType();
	}
}
	
void TaskQueue::wakeup()
{
	if(_flag)
		_flag = false;
	_notEmpty.notifyAll();
}

}//end of namespace wd
 
