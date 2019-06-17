#include "Acceptor.h"
#include "TcpConnection.h"
#include "EventLoop.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
using namespace wd;

void onConnection(const wd::TcpConnectionPtr & conn)
{
    cout << conn->toString() << " has connected!" << endl;
    conn->send("welcome to server.");
}

void onMessage(const wd::TcpConnectionPtr & conn)
{
    //该回调函数的执行时间不宜过长 10ms
    //cout << "onMessage...." << endl;
    string msg = conn->receive();
    cout << "receive msg from client: " << msg << endl;
    //业务逻辑的处理交给
    //decode
    //compute
    //encode
    conn->send(msg);
}

void onClose(const wd::TcpConnectionPtr & conn)
{
    //cout << "onClose...." << endl;
    cout << conn->toString() << " has closed!" << endl;
}

int main(void)
{
	wd::Acceptor acceptor(5000, "192.168.3.160");
	acceptor.init();

    wd::EventLoop loop(acceptor);
    loop.setConnectionCallback(onConnection);
    loop.setMessageCallback(onMessage);
    loop.setCloseCallback(onClose);
    
    loop.loop();

	return 0;
}
