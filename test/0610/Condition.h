//#include<iostream>
//#include<stdio.h>
//#include<pthread.h>
#include"MutexLock.h"
//#include<MutexLock.h>
namespace wd
{
class Condition
:Noncopyable
{
	private:
		MutexLock & _mutex;//MutexLock _mutex这样子是不行的？
		pthread_cond_t _cond;
	public:
		Condition(MutexLock & mutex)
		:_mutex(mutex)
		{
			if(pthread_cond_init(&_cond,nullptr))
			{
				perror("pthread_cond_init");
			}
		}
		~Condition()
		//:_mutex(mutex)
		 //,_cond(cond)
		{
		
			if(pthread_cond_destroy(&_cond))
			{
				perror("(pthread_cond_destroy");
			}
		}

		void wait()
		{
			if(pthread_cond_wait(&_cond,_mutex.getlocker()))//???????
			perror("pthread_cond_wait");

		}

		void notify()
		{
			if(pthread_cond_signal(&_cond))
			{
				perror("pthread_cond_singal");
			}
		}

		void notifyall()
		{
			if(pthread_cond_broadcast(&_cond))
			{
				perror("pthread_cond_broadcast");
			}
		}
	};
}	//end of namespace wd
