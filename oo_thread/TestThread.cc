#include "Thread.h"
#include <unistd.h>
#include <iostream>
#include <memory>
using namespace std;

class Mythread
: public wd::Thread
{
private:
    void run() override
    {
        ::srand(::clock());
        int cnt = 10;
        while(cnt--){
            int number = ::rand() % 100;
            cout << "sub thread" << pthread_self()
                << ": get a number = " << number << endl;
            ::sleep(1);
        }
    }
public:
    ~Mythread() {   cout << "~Mythread()" << endl;  }
};

int main()
{
    cout << " >> main thread " << pthread_self() << endl;
    unique_ptr<wd::Thread> mythread(new Mythread());
    mythread->start();
    mythread->join();
    return 0;
}
