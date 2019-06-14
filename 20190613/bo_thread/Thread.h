#pragma once

#include <pthread.h>
#include <boost/noncopyable.hpp>
#include <iostream>
#include <functional>

using namespace std;

namespace wd
{


class Thread : boost::noncopyable
{
public:
    using ThreadCallback = std::function<void()>;

    Thread(ThreadCallback && cb) 
    :pthid_(0)
    ,isRunning_(false)
    ,cb_(cb)
    {}   //std::cout << "pthid_ = " << pthid_ << std::endl;  }

    ~Thread(); 

    void start();
    void join();

private:
    static void * threadFunc(void *);

private:
    pthread_t pthid_;
    bool isRunning_;
    ThreadCallback cb_;
};

} // namespace wd
