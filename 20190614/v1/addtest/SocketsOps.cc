#include "SocketsOps.h"

void bindOrDie(int sockfd, struct sockaddr* addr)
{
    int ret = bind(sockfd, addr, sizeof(struct sockaddr));
    if(-1 == ret)
    {
        perror("bind");
        close(sockfd);
    }
}
