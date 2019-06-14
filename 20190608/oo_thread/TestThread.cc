#include "Thread.h"
#include "Noncopyable.h"
#include <iostream>
#include <memory>

using namespace std;

class Mythread : public wd::Thread
{
public:
    ~Mythread() { cout << "~Mythread()" << endl; }
private:
    void run() override
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
    //Mythread thread1;
    //Mythread thread2(thread1); 不允许复制

    cout << "main thread_id :" << pthread_self() << endl;
    unique_ptr<wd::Thread> mythread(new Mythread());
    mythread->start();
    mythread->join();

    return 0;
}
