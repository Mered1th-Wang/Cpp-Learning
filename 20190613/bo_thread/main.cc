#include "Thread.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <memory>

using namespace std;

    void process()
    {
        cout << "process()" << endl;
        sleep(1);
    }

int main()
{
    unique_ptr<wd::Thread> mythread
        (new wd::Thread(std::bind(process)));
    mythread->start();
    mythread->join();
}
