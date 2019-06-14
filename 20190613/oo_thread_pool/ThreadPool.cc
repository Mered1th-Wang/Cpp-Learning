#include "ThreadPool.h"

using namespace wd;

ThreadPool::ThreadPool(size_t threadNum, size_t queSize)
:   threadNum_(threadNum),
    queSize_(queSize),
    taskque_(queSize),
    isExit_(false)
{
    threads_.reserve(threadNum_);
}

void ThreadPool::start()
{
    for(size_t idx = 0; idx != threadNum_; ++idx)
    {
        unique_ptr<Thread> up(new WorkThread(*this));
        threads_.push_back(std::move(up)); //禁止拷贝，用移动语义
    }
    for(auto & thread: threads_)
    {
        thread->start();
    }
}

void ThreadPool::addTask(Task * task)
{
    taskque_.push(task);
}

void ThreadPool::stop()
{
    if(!isExit_)
    {
        while(!taskque_.empty())
        { 
        //    sleep(1);
        }

        taskque_.wakeup();

        isExit_ = true;

        for(auto & thread : threads_)
        {
           thread->join();
        }
    }
}

Task * ThreadPool::getTask()
{
    return taskque_.pop();
}

//WorkerThread要执行的
void ThreadPool::threadFunc()
{
    while(!isExit_)
    {
        Task * task = getTask();
        if(task)
        {
            task->process();
        }
    }
}
    
ThreadPool::~ThreadPool()
{
    this->stop(); 
}
