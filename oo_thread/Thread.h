#pragma once

#include "Noncopyable.h"
#include <pthread.h>
#include <functional>
#include <string>
using namespace std;

namespace wd
{

extern __thread const char * threadName;

class Thread 
: Noncopyable
{
public:
	using ThreadCallback = std::function<void()>;

	Thread(ThreadCallback && cb, const string & name = string())
	: _pthid(0)
	, _isRunning(false)
	, _cb(std::move(cb))
	, _name(name)
	{ }

	~Thread();

	void start();
	void join();

private:
	static void * threadFunc(void *);

private:
	pthread_t  _pthid;
	bool _isRunning;
	ThreadCallback _cb;
	string _name;
};

}//end of namespace wd
