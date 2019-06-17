#pragma once

#include "InetAddress.h"
#include "Socket.h"

#include <string>

#define ERROR_CHECK(ret, retval, funcName)      \
{   if(ret == retval)                           \
    {                                           \
        printf("LINE %d ERROR ", __LINE__);     \
        perror(funcName);                       \
        return -1;                              \
    }                                           \
}

namespace wd
{

class Acceptor
{
public:
    explicit Acceptor(const unsigned short& port, const std::string& ip = std::string())
        :   addr_(port, ip), listensock_()
    {}
    
    void init();
    int accept();
    int fd();

private:
    int setReuseAddr(bool);
    int setReusePort(bool);
    int bind();
    int listen();

private:
    InetAddress addr_;
    Socket listensock_;
};

}
