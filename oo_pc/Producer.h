#pragma  once

#include "Thread.h"

namespace wd
{
//前向声明(不完全类型), 可以减少头文件的依赖
class TaskQueue;

class Producer
: public Thread
{
public:
	Producer(TaskQueue & taskque)
	: _taskque(taskque)
	{}
private:
	void run();

private:
	TaskQueue & _taskque;
};

}//end of namespace wd
