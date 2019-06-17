#include "Socket.h"

using namespace wd;

Socket::Socket()
{
    sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == sockfd_) perror("socket");
}

Socket::Socket(int socketfd):sockfd_(socketfd)
{}

Socket::~Socket()
{
    close(sockfd_);
}


//shutdownWrite是主动断开连接时使用
void Socket::shutdownWrite()
{
    shutdown(sockfd_, SHUT_WR);
}

