#include "Thread.h"
#include "Noncopyable.h"
#include <iostream>
#include <memory>

using namespace std;

class MyTask
{
public:
    ~MyTask() { cout << "~Mythread()" << endl; }
    static void process() 
    {
        ::srand(::clock());
        int cnt = 5;
        while(cnt--)
        {
            int num = ::rand() % 100;
            cout << "child thread_id : " << pthread_self()
                << ": get a number = " << num << endl;
            sleep(1);
        }
    }
};

int main()
{
    cout << "main thread_id :" << pthread_self() << endl;
    unique_ptr<wd::Thread> mythread(
        new wd::Thread(MyTask::process));
    mythread->start();
    mythread->join();

    return 0;
}
