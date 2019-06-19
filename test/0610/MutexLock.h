//#include<iostream>
#include<pthread.h>
//#include<stdio.h>
#include<errno.h>
#include"Noncopyable.h"

//using namespace std;
//why 一定要在namepsacez wdz中进行命名空间的命名呢？？？？？？？？？？？？？？
namespace wd{

class MutexLock
: Noncopyable
{
private:
	pthread_mutex_t _mutex;
	bool isLocking;
public:
	MutexLock()
	:isLocking(false)
	{
	
		if(pthread_mutex_init(&_mutex,NULL))
		{
			perror("pthread_mutex_init");
		}
	}
	~MutexLock(){
		if(pthread_mutex_destroy(&_mutex))
		{
			perror("pthread_mutex_destroy");
		}
	}
	void lock()
	{
		if(pthread_mutex_lock(&_mutex))
		{
			perror("pthread_mutex_lock");
		}
		isLocking=true;
	}
	void unlock()
	{
		if(pthread_mutex_unlock(&_mutex))
		{
			perror("pthread_mutex_unlock");
		}
		isLocking=false;
	}
	
	pthread_mutex_t  * getlocker()//这里为什么要加这个mutex
	{
		return &_mutex;
	}
};

class MutexGuard
{
private:
	MutexLock &  _mutex;
public:
	MutexGuard(MutexLock & mutex)
	:_mutex(mutex)
	{
		_mutex.lock();
		
	}
	~MutexGuard()
	//:_mutex(mutex)
	{
		_mutex.unlock();
	}
};

}//end of wd
