#pragma once

#include"Thread.h"
#include"TaskQueue.h"
namespace wd
{
class TaskQueue;
class Comsumer
:public Thread
{
	private:
		TaskQueue & _taskque;
		
	public:
		Comsumer(TaskQueue & taskque)
		:_taskque(taskque)
		{}

		~Comsumer(){}

		void run();
};
}//end od wd;
