#ifndef __WD_TASKQUEUE_H__
#define __WD_TASKQUEUE_H__
#include "MutexLock.h"
#include "Condition.h"

#include <queue>
#include <functional>
using std::queue;

namespace wd
{

using Task = std::function<void()>;
using ElemType = Task ;

class TaskQueue
{
public:
	TaskQueue(size_t sz);

	bool empty() const;
	bool full() const;
	void push(ElemType elem);
	ElemType pop();
	void wakeup();

private:
	size_t _sz;
	queue<ElemType> _que;
	MutexLock _mutex;
	Condition _notEmpty;
	Condition _notFull;
	bool _flag;
};

}//end of namespace wd

#endif
