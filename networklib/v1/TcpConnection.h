#pragma once

#include "SocketIO.h"
#include "Socket.h"
#include "InetAddress.h"
#include "Noncopyable.h"

#include <string>

namespace wd
{

class TcpConnection
: Noncopyable
{
public:
    TcpConnection(int fd);
    ~TcpConnection();

    string receive();
    void send(const string & msg);

    string toString() const;
    void shutdown();

private:
    InetAddress getLocalAddr(int fd);
    InetAddress getPeerAddr(int fd);

private:
    Socket _sock;
    SocketIO _socketIo;
    InetAddress _localAddr;
    InetAddress _peerAddr;
    bool _isShutdownWrite;

};

}
