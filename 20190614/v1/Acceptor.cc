#include "Acceptor.h"

using namespace wd;

int Acceptor::setReuseAddr(bool flag)
{
    int on = flag;
    int ret = setsockopt(listensock_.fd(), SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    ERROR_CHECK(ret, -1, "setsockopt");
}

int Acceptor::setReusePort(bool flag)
{
    int on = flag;
    int ret = setsockopt(listensock_.fd(), SOL_SOCKET, SO_REUSEPORT, &on, sizeof(on)); 
    ERROR_CHECK(ret, -1, "setsockopt");
}

int Acceptor::bind()
{
    int ret = ::bind(listensock_.fd(), (struct sockaddr *)addr_.getSockAddr(), sizeof(struct sockaddr));
    ERROR_CHECK(ret, -1, "bind");
}

int Acceptor::listen()
{
    //backlog:排队建立3次握手队列和刚刚建立3次握手队列的链接数和为10
    int ret = ::listen(listensock_.fd(), 10);
    ERROR_CHECK(ret, -1, "listen");
}

int Acceptor::accept()
{
    int peerfd= ::accept(listensock_.fd(), NULL, NULL);
    ERROR_CHECK(peerfd, -1, "accept");
}

int Acceptor::fd()
{
    return listensock_.fd();
}


void Acceptor::init()
{
    setReuseAddr(true);
    setReusePort(true);
    bind();
    listen();
}
