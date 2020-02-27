#include "Thread.h"
#include <stdio.h>
#include <error.h>

using namespace std;

namespace wd
{

Thread::~Thread()
{
    if(_isRunning){
        pthread_detach(_pthid);
        _isRunning = false;
    }
    cout << "~Thread()" << endl;
}

void Thread::start()
{
    if(pthread_create(&_pthid, nullptr, threadFunc, this)){
        perror("pthread_create");
        return;
    }
    _isRunning = true;
}

void Thread::join()
{
    if(_isRunning){
        pthread_join(_pthid, nullptr);
        _isRunning = false;
    }
}

void * Thread::threadFunc(void * arg)
{
    Thread * pthread = static_cast<Thread*>(arg);
    if(pthread)
        pthread->run();

    return nullptr;
}



}

