#pragma once
#include "Noncopyable.h"

#include <func.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;

namespace wd
{

class Thread : Noncopyable
{
public:
    using ThreadCallback = std::function<void()>;

    Thread(ThreadCallback && cb)
        :_pid(0),
        _isRunning(false),
        _cb(std::move(cb)){}
    
    ~Thread();

    void start();
    void join();
private:
    static void * threadFunc(void *);
private:
    pthread_t _pid;
    bool _isRunning;
    ThreadCallback _cb;
};

}
