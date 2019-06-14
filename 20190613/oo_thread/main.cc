#include "Thread.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <memory>

using namespace std;

class MyThread : public wd::Thread
{
public:
    ~MyThread() {   cout << "~MyThread" << endl;    }
    void run()
    {
        cout << "mythread_id = " << pthread_self() << endl;
        sleep(1);
    }
};

int main()
{
    cout << "main thread_id = " << pthread_self() << endl;
    unique_ptr<wd::Thread> mythread(new MyThread());
    mythread->start();
    mythread->join();
}
