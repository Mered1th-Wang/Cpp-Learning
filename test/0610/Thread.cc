
#include"Thread.h"

//using namespace std;
using std::cout;
using std::endl;

namespace wd
{
	void Thread::start()
	{
		if(pthread_create(&_id,nullptr,threadfun,this))
			{
				perror("pthread_create");
			}
			isRunning=true;
			return;//????
	}
	
	Thread::~Thread()
	{	
	if(isRunning)
	{
		if(pthread_detach(_id));
		{
			perror("pthread_detached");
			isRunning=false;
		}
	}
		cout<<"~Thread()"<<endl;
	}

	void Thread::join()
	{	
	if(isRunning)
	{
		if(pthread_join(_id,nullptr))
		{
			perror("pthread_join");
			isRunning=false;
		}
	}
	}
	
	void* Thread::threadfun(void * arg)
	{
		Thread * pthread=static_cast<Thread*>(arg);
		if(pthread)
		{
			pthread->run();
		}

		return nullptr;
	}

}//end of wd
