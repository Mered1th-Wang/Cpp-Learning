#include "TaskQueue.h"

namespace wd
{

TaskQueue::TaskQueue(size_t queSize)
  : queSize_(queSize),
    que_(),
    mutex_(),
    notEmpty_(mutex_),
    notFull_(mutex_),
    flag_(true)
{}

bool TaskQueue::full() const
{
    return queSize_ == que_.size();
}

bool TaskQueue::empty() const
{
    return que_.empty();
}

void TaskQueue::push(const ElemType & elem)
{
    {
        MutexGuard autolock(mutex_);
        while(full())
        {
            notFull_.wait();
        }
        que_.push(elem);
    }
    notEmpty_.notify();
}

ElemType TaskQueue::pop()
{
    MutexGuard autolock(mutex_);
    while(flag_ && empty())
    {
        notEmpty_.wait();
    }
    if(flag_)
    {
        ElemType ret = que_.front();
        que_.pop();
        notFull_.notify();
        return ret;
    }
    else{
        return ElemType();
    }
}

void TaskQueue::wakeup()
{
    if(flag_) 
        flag_ = false;
    notEmpty_.notifyAll();
}


TaskQueue::~TaskQueue()
{
    std::cout << "~TaskQueue()" << std::endl; 
}

}
