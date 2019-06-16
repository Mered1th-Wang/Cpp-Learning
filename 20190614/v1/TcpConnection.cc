#include "TcpConnection.h"
#include "InetAddress.h"
#include <func.h>

using namespace wd;

TcpConnection::TcpConnection(int fd)
    :sock_(fd),
    socketIO_(fd),
    localAddr_(getLocalAddr()),
    peerAddr_(getPeerAddr()),
    isShutdownWrite_(false)
{}

TcpConnection::~TcpConnection()
{
    if(!isShutdownWrite_)
        shutdown();
}

string TcpConnection::receive()
{
    char buff[65536] = {0};
    socketIO_.readline(buff, sizeof(buff));
    return string(buff);
}
void TcpConnection::send(const string & msg)
{
    socketIO_.writen(msg.c_str(), msg.size());
}

string TcpConnection::toString() const
{
    std::ostringstream oss;
    oss << localAddr_.ip() << ":" << localAddr_.port() << "--->"
        << peerAddr_.ip() << ":" << peerAddr_.port();
    return oss.str();
}
void TcpConnection::shutdown()
{
    if(!isShutdownWrite_)
    {
        isShutdownWrite_ = true;
        sock_.shutdownWrite();
    }
}

InetAddress TcpConnection::getLocalAddr()
{
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr);
    if(-1 == getsockname(sock_.fd(), (struct sockaddr*)&addr, &len))
    {
        perror("getsockname");
    }
    return InetAddress(addr);
}

InetAddress TcpConnection::getPeerAddr()
{
    struct sockaddr_in addr;
    socklen_t len = sizeof(struct sockaddr);
    if(-1 == getpeername(sock_.fd(), (struct sockaddr*)&addr, &len))
    {
        perror("getpeername");
    }
    return InetAddress(addr);
}
