#pragma once

#include <sys/eventfd.h>
#include <poll.h>
#include <functional>
#include <unistd.h>
#include <time.h>
using namespace std;

namespace wd
{

class Eventfd
{

    using EventfdCallBack = function<void()>;

public:
    Eventfd(EventfdCallBack && cb)
    : _fd(createEventfd())
    , _cb(std::move(cb))
    , _isStarted(false)
    {}

    void start();
    void stop();
    void wakeup();
    void handleRead();

private:
      int createEventfd();
    

private:
    int _fd;
    EventfdCallBack _cb;
    bool _isStarted;
};

}
