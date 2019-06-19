#include"Producer.h"
#include"Comsumer.h"
#include<memory>
#include"Thread.h"
#include"TaskQueue.h"

using std::cout;
using std::endl;

int main(void)
{	
	wd::TaskQueue queue;
	unique_ptr<wd::Thread>pro1(new wd::Producer(queue));
	unique_ptr<wd::Thread>pro2(new wd::Producer(queue));
	unique_ptr<wd::Thread>com1(new wd::Comsumer(queue));
	unique_ptr<wd::Thread>com2(new wd::Comsumer(queue));

	pro1->start();
	pro2->start();
	com1->start();
	com2->start();

	pro1->join();
	pro2->join();
	com1->join();
	com2->join();



	return 0;
	

}
