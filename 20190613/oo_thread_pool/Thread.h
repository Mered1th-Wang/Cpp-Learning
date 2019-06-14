#pragma once

#include <pthread.h>
#include <boost/noncopyable.hpp>
#include <iostream>

using std::cout;
using std::endl;

namespace wd
{


class Thread : boost::noncopyable
{
public:
    Thread() 
    :pthid_(0)
    ,isRunning_(false)
    {}   //std::cout << "pthid_ = " << pthid_ << std::endl;  }

    virtual ~Thread(); 

    void start();
    void join();


private:
    virtual void run() = 0;
    static void * threadFunc(void *);

private:
    pthread_t pthid_;
    bool isRunning_;
};

} // namespace wd
