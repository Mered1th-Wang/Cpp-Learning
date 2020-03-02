#include "Eventfd.h"
#include "EventfdThread.h"
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
    wd::EventfdThread eventfd(bind(&Mytask::process, Mytask()));
    eventfd.start();
    
    int cnt = 20;
    while(cnt--) {
        cout << "cnt == "<< cnt << " main thread notify sub thread to do sth.." << endl;
        eventfd.wakeup();
        ::sleep(1);
    }

    cout << ">> main thread eventfd stop." << endl;
    
    eventfd.stop();
    return 0;
}
