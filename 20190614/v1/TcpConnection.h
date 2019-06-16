#pragma once
#include "InetAddress.h"
#include "Socket.h"
#include "SocketIO.h"
#include <string>
#include <sstream>
#include <boost/noncopyable.hpp>
using std::string;

namespace wd
{

class TcpConnection : boost::noncopyable
{
public:
    TcpConnection(int fd); 
    ~TcpConnection();

    string receive();
    void send(const string & msg);

    string toString() const;
    void shutdown();

private:
    InetAddress getLocalAddr();
    InetAddress getPeerAddr();

private:
    Socket sock_;
    SocketIO socketIO_;
    InetAddress localAddr_;
    InetAddress peerAddr_;
    bool isShutdownWrite_;
    
};

} // namespace wd
