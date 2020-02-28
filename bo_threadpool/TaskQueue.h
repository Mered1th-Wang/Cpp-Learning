#pragma once

#include "MutexLock.h"
#include "Condition.h"

#include <queue>
#include <functional>
using namespace std;


namespace wd
{

using ElemType = function<void()>; 

class TaskQueue
{
public:
	TaskQueue(size_t queSize = 10)
	: _queSize(queSize)
	, _que()
	, _mutex()
	, _notFull(_mutex)
	, _notEmpty(_mutex)
	, _flag(true)
	{}

	bool full() const;
	bool empty() const;
	void push(const ElemType & elem);
	ElemType pop();

	void wakeup();

private:
	size_t _queSize;
	queue<ElemType> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	bool _flag;
};

}//end of namespace wd

