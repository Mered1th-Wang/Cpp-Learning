#pragma once
#include "Mutex.h"
#include "Thread.h"
#include "Condition.h"
#include <functional>
#include <vector>
#include <deque>
#include <memory>

using namespace std;

namespace wd
{

class ThreadPool
{
public:
    using Task = std::function<void()>;

    ThreadPool(const string& nameArg = string("ThreadPool")); 
    ~ThreadPool();
    
    void setMaxQueueSize(int maxSize) { maxQueueSize_ = maxSize; }
    void setThreadInitCallback(const Task& cb)
    {   ThreadInitCallback_ = cb;   }

    void start();
    void stop();

    const string& name() const
    {
        return name_;
    }

    size_t queSize() const;

    void run(Task f);

private:
    bool isFull() const;
    void runInThread();
    Task take();


private:
    MutexLock mutex_;
    Condition notEmpty_;
    Condition notFull_;
    string name_;
    Task ThreadInitCallback_;
    vector<unique_ptr<Thread>> threads_;
    deque<Task> queue_;
    size_t maxQueueSize_;
    bool running_;
};

}
