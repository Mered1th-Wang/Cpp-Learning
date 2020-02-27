#pragma once

#include <pthread.h>
#include <iostream>

namespace wd
{

class Thread
{
public:
    Thread() 
    : _pthid(0)
    {}
    virtual ~Thread();

    void start();
    void join();

private:
    virtual void run() = 0;
    static void * threadFunc(void *);

private:
    pthread_t _pthid;
    bool _isRunning;
};

}
