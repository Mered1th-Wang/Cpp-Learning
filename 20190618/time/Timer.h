#pragma once

#include <unistd.h>
#include <signal.h>
#include <poll.h>
#include <sys/timerfd.h>
#include <functional>
#include <iostream>

using namespace std;

namespace wd
{

class Timer
{
    using TimerCallback = function<void()>;
public:
    Timer(int initTime, int intervalTime, TimerCallback && cb)
        : fd_(createTimerfd()),
        initalTime_(initTime),
        intervalTime_(intervalTime),
        cb_(std::move(cb)),
        isStarted_(false)
    {}
    void start();
    void stop();
    void setTimer(int, int);
    void handleRead();


private:
    int createTimerfd();

private:
    int fd_;
    int initalTime_;
    int intervalTime_;
    TimerCallback cb_;
    bool isStarted_;
};

}
