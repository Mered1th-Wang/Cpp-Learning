#include "InetAddress.h"

using namespace wd;


InetAddress::InetAddress(const struct sockaddr_in& addr)
:addr_(addr)
{}

std::string InetAddress::ip() const
{
   return std::string(inet_ntoa(addr_.sin_addr));
}


unsigned short InetAddress::port() const   
{
   return ntohs(addr_.sin_port);   
}


const struct sockaddr_in* InetAddress::getSockAddr() const
{
    return &addr_;
}

