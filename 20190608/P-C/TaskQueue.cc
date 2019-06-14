#include "Condition.h"
#include "MutexLock.h"
#include "Noncopyable.h"
#include "Thread.h"

#include <memory>
#include <func.h>
#include <iostream>
#include <queue>

using namespace std;
using namespace wd;

namespace wd
{

class TaskQueue : Noncopyable
{
public:
    TaskQueue(int x)
        :_queSize(x), _notFull(_mutex), _notEmpty(_mutex){}
    void push(int);
    int pop();
    bool full();
    bool empty();

private:
    size_t _queSize;
    queue<int> _que;
    wd::MutexLock _mutex;
    wd::Condition _notFull;
    wd::Condition _notEmpty;
};

bool TaskQueue::full()
{
    if(_queSize == _que.size())
    {
        return true;
    }
    return false;
}

bool TaskQueue::empty()
{
    if(0 == _que.size())
    {
        return true;
    }
    return false;
}

void TaskQueue::push(int x)
{
    _mutex.lock();
    if(!full())
    {
        _que.push(x);
        _notFull.notifyAll();
        _mutex.unlock();
    }
    else{
        _mutex.unlock();
    }
}

int TaskQueue::pop()
{
    _mutex.lock();
    if(!empty())
    {
        int x = _que.front();
        _que.pop();
        _notEmpty.notifyAll();
        _mutex.unlock();
        return x;
    }
    else{
        _mutex.unlock();
        return -1;
    }
}

}//end of namespace wd

class Producer : public wd::Thread
{
public:
    Producer(wd::TaskQueue & q):_q(q){}
    ~Producer() { cout << "~Producer()" << endl; }

private:
    void run()
    {
        ::srand(::clock());
        while(1)
        {
            int num = ::rand() % 100;
            cout << "Producer " << pthread_self()
                << " made a product " << num << endl;
            _q.push(num);
            sleep(1);
        }
    }

private:
    wd::TaskQueue & _q;
};

class Consumer : public wd::Thread
{
public:
    Consumer(wd::TaskQueue & q):_q(q){}
    ~Consumer() { cout << "~Consumer()" << endl; }

private:
    void run()
    {
        ::srand(::clock());
        while(1)
        {
            int num;
            num = _q.pop();
            if(-1 == num) continue;
            else{
                cout << "Consumer " << pthread_self()
                    << " consume a product " << num << endl;
                sleep(2);
            }
        }
    }

private:
    wd::TaskQueue & _q;
};



int main()
{
    TaskQueue q(5);
    cout << "main thread_id " << pthread_self() << endl;
    unique_ptr<Thread> producer(new Producer(q));
    unique_ptr<Thread> consumer(new Consumer(q));
    producer->start();
    consumer->start();
    producer->join();
    consumer->join();

    return 0;
}
