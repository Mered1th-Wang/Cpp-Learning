#pragma once
#include "InetAddress.h"

#include <func.h>

namespace wd
{

class Socket
{
public:
    explicit Socket();
    explicit Socket(int sockfd);
    ~Socket();
    int fd() const { return sockfd_; }

    void shutdownWrite();
    
private:
    int sockfd_;
};

}
