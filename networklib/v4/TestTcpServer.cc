#include "TcpServer.h"
#include "Threadpool.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
using wd::TcpConnectionPtr;
using wd::TcpServer;
using wd::Threadpool;

Threadpool * gThreadpool = nullptr;

class Task
{
public:
    Task(const string & msg,
         const wd::TcpConnectionPtr & conn)
    : _msg(msg)
    , _conn(conn)
    {}

    void process()
    {
        string response = _msg;
        //_conn->send(response);
        _conn->sendInLoop(response);
    }
private:
    string _msg;
    wd::TcpConnectionPtr _conn;
};


void onConnection(const wd::TcpConnectionPtr & conn)
{
    cout << conn->toString() << " has connected!" << endl;
    conn->send("welcome to server.");
}

void onMessage(const wd::TcpConnectionPtr & conn)
{
    cout << "onMessage...." << endl;
    string msg = conn->receive();
    cout << ">> receive msg from client: " << msg << endl;
    //conn->send(msg);
    //业务逻辑交给线程池处理
    Task task(msg, conn);
    gThreadpool->addTask(std::bind(&Task::process, task));
}

void onClose(const wd::TcpConnectionPtr & conn)
{
    cout << ">> " << conn->toString() << " has closed!" << endl;
}

class EchoServer
{
public:
    void onConnection(const TcpConnectionPtr & conn);
    void onMessage(const TcpConnectionPtr & conn);
    void onClose(const TcpConnectionPtr & conn);
    
    void process(); //业务逻辑处理

private:
    Threadpool _threadpool;
    TcpServer _server;
};


int main()
{
    wd::Threadpool threadpool(4, 10);
    threadpool.start();

    gThreadpool = &threadpool;

    wd::TcpServer server("192.168.1.107", 8888);

    server.setConnectionCallback(onConnection);
    server.setMessageCallback(onMessage);
    server.setCloseCallback(onClose);

    server.start();

    return 0;
}

