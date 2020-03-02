#include "Timer.h"
#include <iostream>
using namespace std;

namespace wd
{

int Timer::createTimerfd()
{
    int fd = ::timerfd_create(CLOCK_REALTIME, 0);
    if(-1 == fd){
        perror("timerfd_create");
    }
    return fd;
}

void Timer::start()
{
    _isStarted = true;
    setTimer(_initalTime, _intervalTime);


    struct pollfd p;
    p.fd = _fd;
    p.events = POLLIN;

    while(_isStarted) {
        int nready = ::poll(&p, 1, 5000);
        if(nready == -1 && errno == EINTR)
            continue;
        else if(nready == -1) {
            perror("poll");
            return;
        }
        else if(nready == 0) {
            cout << ">> poll timeout!" << endl;
        }else {
            if(p.revents & POLLIN) {
                handleRead();
                if(_cb)
                    _cb();
            }
        }
    }
}

void Timer::setTimer(int initalTime, int intervalTime)
{
    struct itimerspec value;
    value.it_value.tv_sec = initalTime;
    value.it_value.tv_nsec = 0;
    value.it_interval.tv_sec = intervalTime;
    value.it_interval.tv_nsec = 0;

    int ret = ::timerfd_settime(_fd, 0, &value, nullptr);
    if(-1 == ret) {
        perror("timerfd_settime");
    }
}

void Timer::stop()
{
    if(_isStarted) {
        setTimer(0, 0);
        _isStarted = false;
    }
}

void Timer::handleRead()
{
    uint64_t howmany;
    int ret = ::read(_fd, &howmany, sizeof(howmany));
    if(ret != sizeof(howmany)) { 
        perror("read");
    }
}

}
