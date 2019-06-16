#pragma once

#include "TaskQueue.h"
#include "Thread.h"
#include <vector>
#include <memory>
#include <functional>
#include <iostream>

using namespace std;

namespace wd
{

using Task = std::function<void()>;

class Thread;
class ThreadPool : boost::noncopyable
{
    friend class WorkThread;
public:
    explicit ThreadPool(size_t threadNum, size_t queSize);
    ~ThreadPool(); 

    void start();
    void stop();
    void addTask(Task && task);

private:
    void threadFunc();
    Task getTask();

private:
    size_t threadNum_;
    size_t queSize_;
    std::vector<std::unique_ptr<Thread>> threads_;
    TaskQueue taskque_;
    bool isExit_;
};

} // namespace wd
