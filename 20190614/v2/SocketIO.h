#pragma once

#include <func.h>

namespace wd
{

class SocketIO
{
public:
    explicit SocketIO(int fd); 

    int readn(char * buff, int len);
    int readline(char * buff, int maxlen);
    int writen(const char * buff, int len);

private:
    int recvPeek(char * buff, int len);

private:
    int sockfd_;
};

}
