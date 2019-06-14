#include "Thread.h"
#include "Mutex.h"
#include <errno.h>
#include <stdio.h>
#include <iostream>

using namespace std;

namespace wd
{

void Thread::start()
{
    MCHECK(pthread_create(&pthid_, nullptr, threadFunc, this));
    isRunning_ = true;
}

void Thread::join()
{
    if(isRunning_)
    {
        /*int ret = */pthread_join(pthid_, nullptr);
        //cout << "ret = " << ret << endl;
        isRunning_ = false;
        //cout << "join()" << endl;
    }
}

Thread::~Thread()
{
    if(isRunning_)
    {
        pthread_detach(pthid_);
        isRunning_ = false;
        //cout << "detach" << endl;
    }
    cout << "~Thread" << endl;
}

void * Thread::threadFunc(void * arg)
{
    Thread * thread_ = (Thread*)arg;
    if(thread_)
    {
        thread_->run();
    }
    return nullptr;
}

}
