#include "Producer.h"
#include "Consumer.h"
#include "TaskQueue.h"

#include <iostream>
#include <memory>
using namespace std;
             
 
int main(void)
{
	wd::TaskQueue queue;
	unique_ptr<wd::Thread> producer1(new wd::Producer(queue));
	unique_ptr<wd::Thread> producer2(new wd::Producer(queue));
	unique_ptr<wd::Thread> consumer1(new wd::Consumer(queue));
	unique_ptr<wd::Thread> consumer2(new wd::Consumer(queue));

	producer1->start();
	producer2->start();
	consumer1->start();
	consumer2->start();

	producer1->join();
	producer2->join();
	consumer1->join();
	consumer2->join();

	return 0;
}
