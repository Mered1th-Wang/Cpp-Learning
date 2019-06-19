#include "Timer.h"
#include "Thread.h"
#include "TimerThread.h"

#include <stdlib.h>

#include <iostream>

using namespace std;

struct Mytask
{
    void process()
    {
        srand(time(NULL));
        int number = rand() % 100;
        cout << "thread " << pthread_self() << " get a number = " << number << endl;
        sleep(1);
    }
};

using namespace wd;

int main()
{
    TimerThread timer(3, 6, bind(&Mytask::process, Mytask()));
    
    timer.start();
    sleep(20);
    cout << " main thread timer stop..." << endl;
    timer.stop();
    return 0;
}
