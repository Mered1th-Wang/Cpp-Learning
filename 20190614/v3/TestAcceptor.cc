#include "Acceptor.h"
#include "TcpConnection.h"
#include "EventLoop.h"
#include "TcpServer.h"

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
    TcpServer server(5000, "192.168.3.160");
    server.setConectionCallback(onConnection);
    server.setMessageCallback(onMessage);
    server.setCloseCallback(onClose);

    server.start();

	return 0;
}
