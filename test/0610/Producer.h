#pragma once
#include"Thread.h"
#include"TaskQueue.h"
namespace wd
{

class Taskqueue;//前项声明，用来避免产生头文件的重复引用
class Producer
:public Thread
{
private:
	TaskQueue & _taskque;

public:
	Producer( TaskQueue & taskque)
	:_taskque(taskque)
	{}

	~Producer(){}
	
	void run();
};

}//end of wd;

