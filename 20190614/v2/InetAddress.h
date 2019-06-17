#pragma once

#include <func.h>
#include <string>
#include <netinet/in.h>


namespace wd
{

class InetAddress
{
public:
    explicit InetAddress(const unsigned short& port, const std::string& ip = std::string())
    {
        memset(&addr_, 0, sizeof(struct sockaddr_in));
        addr_.sin_family = AF_INET;    
        addr_.sin_port = htons(port);
        addr_.sin_addr.s_addr = ip.size() > 0 ? inet_addr(ip.c_str()) : INADDR_ANY;
    }
    explicit InetAddress(const struct sockaddr_in&);
    std::string ip() const;
    unsigned short port() const;
    const struct sockaddr_in* getSockAddr() const;

private:
    struct sockaddr_in addr_;
};


}
