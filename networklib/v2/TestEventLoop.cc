#include "Acceptor.h"
#include "TcpConnection.h"
#include "EventLoop.h"

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
    conn->send(msg);
}

void onClose(const wd::TcpConnectionPtr & conn)
{
    cout << ">> " << conn->toString() << " has closed!" << endl;

}


int main(void)
{
    wd::Acceptor acceptor("192.168.1.107", 8888);
    acceptor.ready();

    wd::EventLoop loop(acceptor);
    loop.setConnectionCallback(onConnection);
    loop.setMessageCallback(onMessage);
    loop.setCloseCallback(onClose);

    loop.loop();

    return 0;

}

