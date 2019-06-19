#pragma once

#include<pthread.h>
#include"Noncopyable.h"

namespace wd
{
class Thread
:Noncopyable
{
private:
	pthread_t _id;
	bool isRunning;
private:
	virtual void run()=0;
	static void *threadfun(void *);//???函数指针怎么用？回调函数吗？
public:
	
	Thread()
	:_id(0)
	 ,isRunning(false)//有参数都要尽量初始化！！！
	{}
	virtual ~Thread();//???生产者和消费者需要使用基类的虚函数	
	void start();
	void join();
	//bool isRunning;

};
}
