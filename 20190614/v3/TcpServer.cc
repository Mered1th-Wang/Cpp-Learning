#include "TcpServer.h"

using namespace wd;

void TcpServer::start()
{
    acceptor_.init();
    loop_.loop();
}


void TcpServer::setConectionCallback(TcpConnectionCallback && cb)
{
    loop_.setConnectionCallback(std::move(cb));
}
void TcpServer::setMessageCallback(TcpConnectionCallback && cb)
{
    loop_.setMessageCallback(std::move(cb));
}
void TcpServer::setCloseCallback(TcpConnectionCallback && cb)
{
    loop_.setCloseCallback(std::move(cb));
}
