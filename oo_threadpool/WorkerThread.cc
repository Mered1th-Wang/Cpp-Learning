#include "WorkerThread.h"
#include "Threadpool.h"

namespace wd
{

void WorkerThread::run()
{
    _threadpool.threadFunc();

}



}

