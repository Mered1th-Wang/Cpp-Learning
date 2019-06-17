#pragma once
#include "InetAddress.h"
#include "Socket.h"
#include "SocketIO.h"
#include <string>
#include <sstream>
#include <memory>
#include <functional>
#include <boost/noncopyable.hpp>
using std::string;

namespace wd
{

class TcpConnection;
using TcpConnectionPtr = std::shared_ptr<TcpConnection>;
using TcpConnectionCallback = std::function<void(const TcpConnectionPtr&)>;

class TcpConnection 
    : boost::noncopyable
    , public std::enable_shared_from_this<TcpConnection>
{
public:
    TcpConnection(int fd); 
    ~TcpConnection();

    string receive();
    void send(const string & msg);

    string toString() const;
    void shutdown();

    void setConnectionCallback(const TcpConnectionCallback & cb);
    void setMessageCallback(const TcpConnectionCallback & cb);
    void setCloseCallback(const TcpConnectionCallback & cb);
    
    void handleConnectionCallback();
    void handleMessageCallback();
    void handleCloseCallback();

private:
    InetAddress getLocalAddr();
    InetAddress getPeerAddr();

private:
    Socket sock_;
    SocketIO socketIO_;
    InetAddress localAddr_;
    InetAddress peerAddr_;
    bool isShutdownWrite_;

    TcpConnectionCallback onConnection_;
    TcpConnectionCallback onMessage_;
    TcpConnectionCallback onClose_;
};

} // namespace wd
