 ///
 /// @file    Condition.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-04-15 14:59:21
 ///
 

#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{

class MutexLock;//类的前向声明 可以减少头文件的依赖

class Condition
: Noncopyable
{
public:
	Condition(MutexLock & mutex);
	~Condition();

	void wait();
	void notify();
	void notifyAll();

private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};

}//end of namespace wd


#endif
