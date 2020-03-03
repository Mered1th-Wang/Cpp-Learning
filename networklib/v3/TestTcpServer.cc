#include "TcpServer.h"
#include "Acceptor.h"
#include "TcpConnection.h"
#include "EventLoop.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

using namespace wd;

#if 0
class Task
{
public:
    Task(const string & msg,
         wd::TcpConnectionPtr & conn)
    : _msg(msg)
    , _conn(conn)
    {}

    void process()
    {
        string response = _msg;
        _conn->send(response);
        //_conn->sendInLoop(response);
    }
private:
    string _msg;
    wd::TcpConnectionPtr _conn;
};

#endif

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
    conn->send(msg);
    //业务逻辑交给线程池处理
    //Task task(msg, conn);
    //Threadpool * pthreadpool;
    //pthreadpool->addTask(std::bind(&Task::process, task));
}

void onClose(const wd::TcpConnectionPtr & conn)
{
    cout << ">> " << conn->toString() << " has closed!" << endl;
}

int main()
{
    wd::TcpServer server("192.168.1.107", 8888);

    server.setConnectionCallback(onConnection);
    server.setMessageCallback(onMessage);
    server.setCloseCallback(onClose);

    server.start();

    return 0;
}

