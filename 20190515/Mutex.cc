#include <pthread.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <unistd.h>

using namespace std;

queue<int> q; 

class MutexLock
{
    friend class Condition;

public:
    MutexLock()
    {
        pthread_mutex_init(&_mutex, NULL);
        cout << "MutexLock()" << endl;
    }
    void lock()
    {
        pthread_mutex_lock(&_mutex);        
    }
    void unlock()
    {
        pthread_mutex_unlock(&_mutex);
    }
    ~MutexLock()
    {
        pthread_mutex_destroy(&_mutex);
    }
    void getMutexAddress()
    {
        printf("%p\n", &_mutex);
    }
private:
    pthread_mutex_t _mutex;
};

class Condition
{
public:
    Condition(MutexLock& mutex):_mutex(mutex)
    {
        pthread_cond_init(&_cond, NULL);
        cout << "Condition()" << endl;
    }
    void wait()
    {
        pthread_cond_wait(&_cond, &_mutex._mutex);
    }
    void notify()
    {
        pthread_cond_signal(&_cond);
    }
    void notifyall()
    {
        pthread_cond_broadcast(&_cond);
    }
    ~Condition()
    {
        pthread_cond_destroy(&_cond);
        cout << "~Conditon()" << endl;
    }
    void getMutexAddress()
    {
        printf("%p\n", &_mutex._mutex);
    }

private:
    pthread_cond_t _cond;
    MutexLock& _mutex;
};

MutexLock tMutex;
Condition tCond(tMutex);

void* consumer(void *p)
{
    while(1)
    {
        tMutex.lock();
        if(!q.size())
        {
            tCond.wait();
        }
        q.pop();
        cout << "Consume OK! " << "size of queue = " << q.size() << endl;
        tMutex.unlock();
        sleep(rand() % 5);
    }
}

void* producer(void *p)
{
    while(1)
    {
        tMutex.lock();
        cout << "Produce OK! " << "size of queue = " << q.size() << endl;
        q.push(1);
        tMutex.unlock();
        tCond.notify();
        sleep(rand() % 3);
    }
}




int main()
{
    //验证cond的是同一把锁
    tMutex.getMutexAddress();
    tCond.getMutexAddress();
    
    pthread_t pid, cid;
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);

    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
    return 0;
}
