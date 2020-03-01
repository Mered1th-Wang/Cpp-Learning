#pragma once

namespace wd
{


class Socket
{
public:
    Socket();
    explicit
    Socket(int fd);

    int fd() const;

    void shutdownWrite();

    ~Socket();

private:
    int _fd;
};

}
