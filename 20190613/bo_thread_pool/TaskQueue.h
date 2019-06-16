#pragma once

#include "Mutex.h"
#include "Condition.h"
#include <queue>
#include <functional>
#include <iostream>

namespace wd
{
using ElemType = std::function<void()>;

class TaskQueue
{
public:
    explicit TaskQueue(size_t); 
    
    ~TaskQueue(); 

    bool full() const;
    bool empty() const;
    void push(const ElemType & elem);
    ElemType pop();
    void wakeup();

private:
    size_t queSize_;
    std::queue<ElemType> que_;
    MutexLock mutex_;
    Condition notEmpty_;
    Condition notFull_;
    bool flag_;
};

}
