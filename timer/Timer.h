#pragma once

#include <sys/timerfd.h>
#include <poll.h>
#include <functional>
#include <unistd.h>
#include <time.h>
using namespace std;

namespace wd
{

class Timer
{

    using TimerCallBack = function<void()>;

public:
    Timer(int initTime, int intervalTime, TimerCallBack && cb)
    : _fd(createTimerfd())
    , _initalTime(initTime)
    , _intervalTime(intervalTime)
    , _cb(std::move(cb))
    , _isStarted(false)
    {}

    void start();
    void stop();
    void setTimer(int initTime, int intervalTime);

    void handleRead();

private:
      int createTimerfd();
    

private:
    int _fd;
    int _initalTime;
    int _intervalTime;
    TimerCallBack _cb;
    bool _isStarted;
};

}
