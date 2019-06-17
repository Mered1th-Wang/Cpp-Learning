#pragma once

#include "Acceptor.h"
#include "EventLoop.h"

namespace wd
{

class TcpServer
{
public:
    explicit TcpServer(const unsigned short& port, const std::string& ip = std::string()) 
        :acceptor_(port, ip),
        loop_(acceptor_)
    {}
    
    void start();

    void setConectionCallback(TcpConnectionCallback && cb);
    void setMessageCallback(TcpConnectionCallback && cb);
    void setCloseCallback(TcpConnectionCallback && cb);

private:
    Acceptor acceptor_;
    EventLoop loop_;
};

}
