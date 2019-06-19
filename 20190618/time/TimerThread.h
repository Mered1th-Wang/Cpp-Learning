#pragma once
#include "Timer.h"
#include "Thread.h"

namespace wd
{

class TimerThread
{
    using TimerCallback = function<void()>;
public:
    TimerThread(int initTime, int intervalTime, TimerCallback && cb)
    : timer_(initTime, intervalTime, std::move(cb)),
    thread_(bind(&Timer::start, &timer_))
    {}

    void start()
    {
        thread_.start();
    }
    
    void stop()
    {
        timer_.stop();
        thread_.join();
    }


private:
    Timer timer_;
    Thread thread_;
};

}
