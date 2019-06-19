#include"Comsumer.h"
#include"TaskQueue.h"

using std::cout;
using std::endl;

namespace wd
{
	void Comsumer::run()
	{
		int i=5;
		while(--i)
		{	
			//int ret=_taskque.front();
			int number=_taskque.pop();

			cout<<"线程TD:"<<pthread_self()
				<<"number="<<number<<endl;
		}
	}
}//end of wd;

