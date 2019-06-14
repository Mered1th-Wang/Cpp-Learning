#include "ThreadPool.h"
#include <assert.h>
#include <stdio.h>

#include <iostream>

using namespace wd;

ThreadPool::ThreadPool(const string& nameArg) 
  : mutex_(),
    notEmpty_(mutex_),
    notFull_(mutex_),
    name_(nameArg),
    maxQueueSize_(0),
    running_(false)
{

}

ThreadPool::~ThreadPool()
{
    if(running_)
    {
        stop();
    }
}

void ThreadPool::start(int numThreads)
{
    assert(threads_.empty());
    running_ = true;
    threads_.reserve(numThreads);
    for(int i = 0; i < numThreads; ++i)
    {
        char id[32];
        snprintf(id, sizeof(id), "%d", i + 1);
        threads_.emplace(new Thread(std::bind(&ThreadPool::runInThread, this), name_+id));
        threads_[i]->start();
    }
    if(numThreads == 0 && ThreadInitCallback_)
    {
        ThreadInitCallback_();
    }
}


void start();
void stop();

