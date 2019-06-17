#pragma once

#include "Acceptor.h"
#include "TcpConnection.h"
#include <func.h>
#include <assert.h>
#include <iostream>
#include <map>
#include <vector>
#include <memory>

using namespace std;

namespace wd
{


class EventLoop
{
public:
    explicit EventLoop(Acceptor&);
    void loop();
    void unloop();

    void setConnectionCallback(const TcpConnectionCallback && cb);
    void setMessageCallback(const TcpConnectionCallback && cb);
    void setCloseCallback(const TcpConnectionCallback && cb);

private:
    void waitEpollFd();
    void handleNewConnection();
    void handleMessage(int);
    int createEpollFd();
    void addEpollFdRead(int);
    void delEpollFdRead(int);
    bool isConnectionClosed(int);

private:
    int efd_;
    Acceptor& acceptor_;
    vector<struct epoll_event> eventList_;
    map<int, TcpConnectionPtr> conns_;
    bool isLooping_;

    TcpConnectionCallback onConnection_;
    TcpConnectionCallback onMessage_;
    TcpConnectionCallback onClose_;
};

}
