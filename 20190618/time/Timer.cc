#include "Timer.h"

using namespace wd;

int Timer::createTimerfd()
{
    int fd = timerfd_create(CLOCK_REALTIME, 0);
    if(-1 == fd)
    {
        perror("timerfd_create");
    }
    return fd;
}

void Timer::start()
{
    isStarted_ = true;
    setTimer(initalTime_, intervalTime_);
    struct pollfd pfd;
    pfd.fd = fd_;
    pfd.events = POLLIN;

    while(isStarted_)
    {
        int nready = poll(&pfd, 1, 5000);
        if(nready == -1 && errno == EINTR)
            continue;
        else if(nready == -1){
            perror("poll");
            return;
        }else if(nready == 0){
            cout << "poll timeout" << endl;
        }else{
            if(pfd.revents & POLLIN){
                handleRead();//处理读事件
                if(cb_)
                    cb_();//执行任务
            }
        }
    }
}

void Timer::handleRead()
{
    uint64_t howmany;   //8字节大小
    int ret = read(fd_, &howmany, sizeof(howmany));
    if(ret != sizeof(howmany))
    {
        perror("read");
    }
}

void Timer::stop()
{
    if(isStarted_){
        setTimer(0, 0);
        isStarted_ = false;
    }
}

void Timer::setTimer(int initalTime, int intervalTime)
{
    struct itimerspec value;
    value.it_value.tv_sec = initalTime;
    value.it_value.tv_nsec = 0;
    value.it_interval.tv_sec = intervalTime;
    value.it_interval.tv_nsec = 0;
    
    int ret = ::timerfd_settime(fd_, 0, &value, nullptr);
    if(-1 == ret){
        perror("timerfd_settime");
    }
}
