#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__
#include "Noncopyable.h"

#include <pthread.h>
#include <functional>

namespace wd
{

class Thread
: Noncopyable
{
public:
	using ThreadCallback = std::function<void()>;
	Thread(ThreadCallback && cb);

	void start();
	void join();

	~Thread();

private:
	static void * threadFunc(void *);

private:
	pthread_t _pthid;
	ThreadCallback _cb;
	bool _isRunning; 
};

}//end of namespace wd

#endif
