#include "Consumer.h"

#include "TaskQueue.h"

#include <unistd.h>
#include <iostream>
using namespace std;
             

namespace wd
{

void Consumer::get(TaskQueue & taskque)
{
	int cnt = 10;
	while(cnt--) {
		int number = taskque.pop();
		cout << "consumer sub thread " << pthread_self() 
			 << ">> consumer get a number = " << number << endl;
		::sleep(2);
	}
}


}//end of namespace wd
 
