#pragma once

#include "MyConf.h"
#include "TcpServer.h"
#include "Threadpool.h"
#include "MyTask.h"

namespace wd
{

class SpellCorrectServer
{
public:
    explicit SpellCorrectServer(const string & cfgFileName);

    void start();
    void onConnection(const TcpConnectionPtr & conn);
    void onMessage(const TcpConnectionPtr & conn);
    void onClose(const TcpConnectionPtr & conn);

private:
    MyConf conf_;
    TcpServer tcpServer_;
    Threadpool threadpool_;
};

}
