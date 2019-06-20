#include "Threadpool.h"
#include "TcpServer.h"
#include "EditDistance.h"
#include "MyTask.h"
#include "MyDict.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
using namespace wd;

Threadpool * gThreadpool = nullptr;

MyDict* MyDict::pInstance_ = new MyDict();  //饱汉模式

void onConnection(const wd::TcpConnectionPtr & conn)
{
	cout << conn->toString() << " has connected!" << endl;
	conn->send("welcome to server.");
}


void onMessage(const wd::TcpConnectionPtr & conn)
{
	string msg = conn->receive();
	cout << ">> receive msg from client: " << msg << endl;
    
    MyDict * p = MyDict::createInstance();
    p->init("/home/wj/C++/project/data/dict.dat", "/home/wj/C++/project/data/index.dat");
    

    MyTask mytask(*p, msg, conn);
    gThreadpool->addTask(std::bind(&MyTask::execute, mytask));
    
}

void onClose(const wd::TcpConnectionPtr & conn)
{
	cout << conn->toString() << " has closed!" << endl;
}

using namespace wd;


int main(void)
{
	wd::Threadpool threadpool(4, 10); 
	threadpool.start();
	
	gThreadpool = &threadpool;

	wd::TcpServer server("192.168.3.160", 5000);

	server.setConnectionCallback(onConnection);
	server.setMessageCallback(onMessage);
	server.setCloseCallback(onClose);

	server.start();
	return 0;
}
