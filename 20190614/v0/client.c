#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

void do_service(int sockfd);

int main()
{
    int peerfd = socket(PF_INET, SOCK_STREAM, 0);
    if(-1 == peerfd) ERR_EXIT("socket");

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("192.168.3.160"); //localhost
    addr.sin_port = htons(5000);
    socklen_t len = sizeof(addr);
    if(-1 == connect(peerfd, (struct sockaddr*)&addr, len))
        ERR_EXIT("connect");
    
    char buf[1024] = {0};
    //read从内核态peerfd中尝试读1024个字节到buf中
    read(peerfd, buf, sizeof(buf));
    printf("%s\n", buf);

    do_service(peerfd);
    return 0;
}

void do_service(int sockfd)
{
    char recvbuf[1024] = {0};
    char sendbuf[1024] = {0};

    while(1)
    {
        //fgets从stdin中读取1024个字节到sendbuf中
        fgets(sendbuf, sizeof(sendbuf), stdin);
        write(sockfd, sendbuf, strlen(sendbuf));
        int readn = read(sockfd, recvbuf, sizeof(recvbuf));
        if(-1 == readn)
        {
            if(errno == EINTR)
            {
                continue;
            }
            ERR_EXIT("read");
        }
        else if(0 == readn)
        {
            printf("server close!\n");
            close(sockfd);
            exit(EXIT_SUCCESS);
        }
        printf("receive msg : %s\n", recvbuf);
        memset(recvbuf, 0, sizeof(recvbuf));
        memset(sendbuf, 0, sizeof(sendbuf));
    }
}
