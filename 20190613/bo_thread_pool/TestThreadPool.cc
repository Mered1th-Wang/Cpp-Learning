#include <time.h>
#include <stdlib.h>
#include "ThreadPool.h"
#include <iostream>
using namespace std;
using namespace wd;

class MyTask 
{
public:
    void process()
    {
        ::srand(time(NULL));
        int num = ::rand() % 100;
        cout << "sub thread " << pthread_self()
            << " create a num " << num << endl;
        //sleep(2);
    }
};

int main()
{
    ThreadPool threadpool(4, 10);
    threadpool.start();
    int cnt = 20;
    while(cnt--)
    {
        threadpool.addTask(bind(&MyTask::process, MyTask()));
        cout << "cnt = " << cnt << endl;
    }
    threadpool.stop();
    return 0;
}

