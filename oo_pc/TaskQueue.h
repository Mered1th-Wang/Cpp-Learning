#pragma once

#include "MutexLock.h"
#include "Condition.h"

#include <queue>
using namespace std;


namespace wd
{

class TaskQueue
{
public:
	TaskQueue(size_t queSize = 10)
	: _queSize(queSize)
	, _que()
	, _mutex()
	, _notFull(_mutex)
	, _notEmpty(_mutex)
	{}

	bool full() const;
	bool empty() const;
	void push(int number);
	int pop();

private:
	size_t _queSize;
	queue<int> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
};

}//end of namespace wd

