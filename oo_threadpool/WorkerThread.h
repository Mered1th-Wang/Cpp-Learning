#pragma once

#include "Thread.h"

namespace wd
{

class Threadpool;

class WorkerThread
:public Thread
{
public:
    WorkerThread(Threadpool & threadpool)
    : _threadpool(threadpool)
    {}

    void run();

private:
    Threadpool & _threadpool;
};

}
