#include "SocketIO.h"

using namespace wd;

SocketIO::SocketIO(int fd)
    :sockfd_(fd)
{}

int SocketIO::readn(char * buff, int len)
{
    int left = len;
    char * p = buff;
    while(left)
    {
        int ret = read(sockfd_, p, left);
        if(-1 == ret && errno == EINTR)
            continue;
        else if(-1 == ret)
        {
            perror("read");
            return len - left;
        }
        else if(0 == ret)
        {
            return len - left;
        }
        else{
            left -= ret;
            p += ret;
        }
    }
    return len - left;
}

int SocketIO::readline(char * buff, int maxlen)
{
    int left = maxlen - 1;
    char * p = buff;
    int ret;
    int total = 0;
    while(left)
    {
        ret = recvPeek(p, left);
        for(int idx = 0;idx != ret;++idx)
        {
            if(p[idx] == '\n')
            {
                int sz = idx + 1;
                readn(p, sz);
                total += sz;
                p += sz;
                *p = '\0';
                return total;
            }
        }
        //如果没有'\n'
        readn(p, ret);
        left -= ret;
        p += ret;
        total += ret;
    }
}

int SocketIO::recvPeek(char * buff, int len)
{
    int ret;
    do{
        ret = ::recv(sockfd_, buff, len, MSG_PEEK);
    }while(-1 == ret && errno == EINTR);
    return ret;
}


int SocketIO::writen(const char * buff, int len)
{
    int left = len;
    const char * p = buff;
    while(left)
    {
        int ret = ::write(sockfd_, p, left);
        if(-1 == ret && errno == EINTR) continue;
        else if(-1 == ret)
        {
            perror("write");
            return len - left;
        }
        else{
            left -= ret;
            p += ret;
        }
    }
}

