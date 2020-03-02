#include "Eventfd.h"
#include <iostream>
using namespace std;

namespace wd
{

int Eventfd::createEventfd()
{
    int fd = ::eventfd(10, 0);
    if(-1 == fd){
        perror("eventfd");
    }
    return fd;
}

void Eventfd::start()
{
    _isStarted = true;


    struct pollfd p;
    p.fd = _fd;
    p.events = POLLIN;

    while(_isStarted) {
        int nready = ::poll(&p, 1, 5000);
        if(nready == -1 && errno == EINTR)
            continue;
        else if(nready == -1) {
            perror("poll");
            return;
        }
        else if(nready == 0) {
            cout << ">> poll timeout!" << endl;
        }else {
            if(p.revents & POLLIN) {
                handleRead();
                if(_cb)
                    _cb();
            }
        }
    }
}

void Eventfd::wakeup()
{
    uint64_t one = 1;
    int ret = ::write(_fd, &one, sizeof(one));
    if(ret != sizeof(one)){
        perror("write");
    }
}

void Eventfd::stop()
{
    if(_isStarted) {
        _isStarted = false;
    }
}

void Eventfd::handleRead()
{
    uint64_t howmany;
    int ret = ::read(_fd, &howmany, sizeof(howmany));
    if(ret != sizeof(howmany)) { 
        perror("read");
    }
}

}
