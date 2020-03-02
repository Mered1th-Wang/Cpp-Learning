#include "Thread.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

Thread::~Thread()
{
    if(_isRunning){
        pthread_detach(_pid);
        _isRunning = false;
    }
    cout << "~Thread()" << endl;
}

void Thread::start()
{
    if(pthread_create(&_pid, nullptr, threadFunc, this))
    {
        perror("pthread_create");
        return;
    }
    _isRunning = true;

}

void Thread::join()
{
    if(_isRunning)
    {
        pthread_join(_pid, nullptr);
        _isRunning = false;
    }
}

void * Thread::threadFunc(void * arg)
{
    Thread * pthread = static_cast<Thread*>(arg);
    if(pthread)
        pthread->_cb();
    return nullptr;
}

}//end of namespace wd


