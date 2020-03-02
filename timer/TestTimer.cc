#include "Timer.h"
#include "TimerThread.h"
#include <time.h>
#include <iostream>
#include <functional>
using namespace std;

struct Mytask
{
    void process()
    {
        ::srand(::time(NULL));
        int number = ::rand() % 100;
        cout << ">> get a number = "<< number << endl;
    }
};

int main()
{
    wd::TimerThread timer(3, 6, bind(&Mytask::process, Mytask()));
    timer.start();
    
    ::sleep(20);

    cout << ">> main thread timer stop." << endl;
    
    timer.stop();
    return 0;
}
