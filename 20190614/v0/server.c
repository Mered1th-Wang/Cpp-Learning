#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define ERROR_CHECK(ret, retval, funcName, listenfd)      \
{   if(ret == retval)                           \
    {                                           \
        printf("LINE %d ERROR ", __LINE__);     \
        perror(funcName);                       \
        close(listenfd);                        \
        return -1;                              \
    }                                           \
}

int main()
{
    int listenfd = socket(AF_INET, SOCK_STREAM, 0); //ipv4, full-duplex byte streams
    ERROR_CHECK(listenfd, -1, "socket", listenfd);
    //默认情况下是阻塞的
    int on = 1;

    //在一个服务端程序主动关闭之后，立马可以重启
    //SO_REUSEADDR主要改变了系统对待通配符IP地址冲突的方式
    int ret;
    ret = setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    ERROR_CHECK(ret, -1, "setsockopt", listenfd);

#if 1
    //实现系统级别的负载均衡，一个服务器程序可以在同一台物理主机的同一时刻启动多次
    //表示允许创建端口号相同但IP地址不同的多个socket描述符,即端口复用
    ret = setsockopt(listenfd, SOL_SOCKET, SO_REUSEPORT, &on, sizeof(on));
    ERROR_CHECK(ret, -1, "setsockopt", listenfd);
#endif

    struct sockaddr_in serverAddr;
    printf("sizeof(struct sockaddr_in) = %ld\n", sizeof(struct sockaddr_in));
    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET; //IPv4
    serverAddr.sin_port = htons(8888); //主机字节序转网络字节序
    serverAddr.sin_addr.s_addr = INADDR_ANY; //inet_addr("0.0.0.0")通配符IP

    ret = bind(listenfd, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr));
    ERROR_CHECK(ret, -1, "bind", listenfd);

    ret = listen(listenfd, 10);
    ERROR_CHECK(ret, -1, "listen", listenfd);

    while(1)
    {
        int peerFd = accept(listenfd, NULL, NULL);
        while(1)
        {
            char sendbuf[1024] = "Welcome to server!";
            ret = write(peerFd, sendbuf, strlen(sendbuf));
            memset(sendbuf, 0, 1024);
            printf("> client data:\n");
  
            char recvbuf[1024] = {0};
            ret = read(peerFd, recvbuf, 1024);
            if(0 == ret) 
            {
                printf("--------\n");
                break;
            }
            printf("%s\n", recvbuf);
        }
    }
    close(listenfd);
    return 0;
}

