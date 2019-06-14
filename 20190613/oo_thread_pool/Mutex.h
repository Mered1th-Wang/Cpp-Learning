#pragma once
#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <assert.h>
#include <boost/noncopyable.hpp>

#include <muduo/base/Types.h>
#include <muduo/base/CurrentThread.h>

#ifdef CHECK_PTHREAD_RETURN_VALUE

#ifdef NDEBUG
    __BEGIN_DECLS
extern void __assert_perror_fail (int errnum,
                                  const char *file,
                                  unsigned int line,
                                  const char *function)
    noexcept __attribute__ ((__noreturn__));
    __END_DECLS
#endif

#define MCHECK(ret) ({ __typeof__ (ret) errnum = (ret);         \
                     if (__builtin_expect(errnum != 0, 0))    \
                     __assert_perror_fail (errnum, __FILE__, __LINE__, __func__);})

#else  // CHECK_PTHREAD_RETURN_VALUE

#define MCHECK(ret) ({ __typeof__ (ret) errnum = (ret);         \
                     assert(errnum == 0); (void) errnum;})

#endif // CHECK_PTHREAD_RETURN_VALUE

using namespace muduo;

namespace wd
{

class MutexLock : boost::noncopyable
{
public:
    MutexLock()
    {
        MCHECK(pthread_mutex_init(&mutex_, nullptr));
    }

    ~MutexLock() 
    {
        MCHECK(pthread_mutex_destroy(&mutex_));
    }

    void lock()
    {
        MCHECK(pthread_mutex_lock(&mutex_));
    }

    void unlock()
    {
        MCHECK(pthread_mutex_unlock(&mutex_));
    }

    pthread_mutex_t * getPthreadMutex() { return & mutex_; }

private:
    friend class Condition;

private:
    pthread_mutex_t mutex_;
};

class MutexGuard : boost::noncopyable
{
public:
    MutexGuard(MutexLock& mutex)
        : mutex_(mutex)
    {
        mutex_.lock();
    }

    ~MutexGuard()
    {
        mutex_.unlock();
    }

private:
    MutexLock& mutex_;
};


} // namespace wd
