#pragma once

#include "Thread.h"

namespace wd
{

class TaskQueue;

class Consumer
: public Thread
{
public:
	Consumer(TaskQueue & taskque)
	: _taskque(taskque)
	{}

private:
	void run();

private:
	TaskQueue & _taskque;
};


}//end of namespace wd
