#pragma once

#include "TaskQueue.h"
#include "WorkThread.h"
#include "Task.h"
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

namespace wd
{

class Thread;
class ThreadPool : boost::noncopyable
{
    friend class WorkThread;
public:
    explicit ThreadPool(size_t threadNum, size_t queSize);
    ~ThreadPool(); 

    void start();
    void stop();
    void addTask(Task * task);

private:
    void threadFunc();
    Task * getTask();

private:
    size_t threadNum_;
    size_t queSize_;
    vector<unique_ptr<Thread>> threads_;
    TaskQueue taskque_;
    bool isExit_;
};

} // namespace wd
