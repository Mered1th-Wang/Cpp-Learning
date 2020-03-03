#include "Threadpool.h"

#include <unistd.h>

#include <iostream>
using namespace std;
             
namespace wd
{

void Threadpool::start()
{
	for(size_t idx = 0; idx != _threadNum; ++idx) {
		unique_ptr<Thread> up(new Thread(
			bind(&Threadpool::threadFunc, this)			
		));
		_threads.push_back(std::move(up));
	}

	for(auto & thread : _threads) {
		thread->start();
	}
}

void Threadpool::addTask(Task && task)
{
	_taskque.push(std::move(task));
}

void Threadpool::stop()
{
	if(!_isExit) {

		//当任务队列中还有任务没有执行完毕时，等待
		while(!_taskque.empty()) {
			//::usleep(1000);
			::sleep(2);
		}


		//有个潜在风险: 当_isExit被修改之前，任务已经执行完毕，
		//每一个子线程都阻塞在了getTask方法之上，此时再将_isExit
		//设置为true，已经没有意义了.
		_isExit = true;

		//唤醒所有的子线程
		_taskque.wakeup();

		for(auto & thread : _threads) {
			thread->join();
		}
	}
}

Task Threadpool::getTask()
{
	return _taskque.pop();
}

//WorkerThread要执行的, 子线程中执行
void Threadpool::threadFunc()
{
	while(!_isExit){
		Task task = getTask();
		if(task) {
			task();//执行任务是有时间的
		}
	}
}

}//end of namespace wd
 
