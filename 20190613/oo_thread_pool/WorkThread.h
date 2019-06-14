#pragma once

#include "Thread.h"

namespace wd
{
class ThreadPool;
class WorkThread : public Thread
{
public:
    explicit WorkThread(ThreadPool & threadpool); 
    ~WorkThread();

private:
    void run();

private:
    ThreadPool & threadpool_;
};

} // namespace wd
