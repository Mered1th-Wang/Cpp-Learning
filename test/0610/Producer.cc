#include<time.h>
#include"Producer.h"
#include<math.h>
using std::cout;
using std::endl;

namespace wd
{
	void Producer::run()
	{
		int i=5;
		while(--i)
		{
			::srand(time(NULL));
			int number=rand()%100;
			_taskque.push(number);
			
			cout<<"<<线程ID："<<pthread_self()
				<<"number:"<<endl;
		}
	}
}//end of wd;
