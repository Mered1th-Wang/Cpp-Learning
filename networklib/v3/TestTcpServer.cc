#include "TcpServer.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

void onConnection(const wd::TcpConnectionPtr & conn)
{
    cout << conn->toString() << " has connected!" << endl;
    conn->send("welcome to server.");
}

void onMessage(const wd::TcpConnectionPtr & conn)
{
    string msg = conn->receive();
    cout << ">> receive msg from client: " << msg << endl;
    
    //业务逻辑交给线程池处理
    
    conn->send(msg);
}

void onClose(const wd::TcpConnectionPtr & conn)
{
    cout << ">> " << conn->toString() << " has closed!" << endl;
}

int main(void)
{
    wd::TcpServer server("192.168.1.107", 8888);

    server.setConnectionCallback(onConnection);
    server.setMessageCallback(onMessage);
    server.setCloseCallback(onClose);

    server.start();

    return 0;
}

