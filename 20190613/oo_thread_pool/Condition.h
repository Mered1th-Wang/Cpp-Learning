#pragma once

#include "Mutex.h"

#include <boost/noncopyable.hpp>

namespace wd
{

class Condition : boost::noncopyable
{
public:
    Condition(MutexLock & mutex) 
    : mutex_(mutex)
    {
        MCHECK(pthread_cond_init(&pcond_, nullptr));
    }

    ~Condition() 
    {
        MCHECK(pthread_cond_destroy(&pcond_));
    }

    void wait()
    {
        MCHECK(pthread_cond_wait(&pcond_, mutex_.getPthreadMutex()));
    }

    void notify()
    {
        MCHECK(pthread_cond_signal(&pcond_));
    }

    void notifyAll()
    {
        MCHECK(pthread_cond_broadcast(&pcond_));
    }

private:
    MutexLock& mutex_;
    pthread_cond_t pcond_;
};


} // namespace wd
