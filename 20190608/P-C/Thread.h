#pragma once
#include "Noncopyable.h"

#include <func.h>
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

class Thread : Noncopyable
{
public:
    Thread():_pid(0), _isRunning(false){}
    
    virtual ~Thread();

    void start();
    void join();
private:
    virtual void run() = 0;
    static void * threadFunc(void *);
private:
    pthread_t _pid;
    bool _isRunning;
};

}
