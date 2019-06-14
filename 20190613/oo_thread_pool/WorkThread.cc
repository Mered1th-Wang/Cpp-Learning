#include "WorkThread.h"
#include "ThreadPool.h"

using namespace wd;

WorkThread::WorkThread(ThreadPool & threadpool)
:  threadpool_(threadpool)
{}

void WorkThread::run()
{
    threadpool_.threadFunc();
}

WorkThread::~WorkThread()
{
    cout << "~WorkThread()" << endl;
}
