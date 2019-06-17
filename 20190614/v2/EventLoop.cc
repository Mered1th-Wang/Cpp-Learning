#include "EventLoop.h"

using namespace wd;
using namespace std;

EventLoop::EventLoop(Acceptor& acceptor)
    :efd_(createEpollFd())
    ,acceptor_(acceptor)
    ,eventList_(1024)
     ,isLooping_(false)
{
    addEpollFdRead(acceptor_.fd());
}

void EventLoop::loop()
{
    isLooping_ = true;
    while(isLooping_)
    {
        waitEpollFd();
    }
}

void EventLoop::unloop()
{
    if(isLooping_)
    {
        isLooping_ = false;
    }
}

void EventLoop::waitEpollFd()
{
    int nready;
    do{
        //每5秒返回一次
        nready = epoll_wait(efd_, &*eventList_.begin(), eventList_.size(), 5000);
    }while(nready == -1 && errno == EINTR);

    if(-1 == nready)
    {
        perror("epoll_wait");
        return;
    }else if(nready == 0){
        cout << ">> epoll_wait timeout!" << endl;
    }else{
        if(nready == (int)eventList_.size()){
            eventList_.resize(2 * nready);
        }
        for(int idx = 0; idx != nready; ++idx)
        {
            int fd = eventList_[idx].data.fd;
            if(acceptor_.fd() == fd)
            {
                //处理新连接
                //表示对应的文件描述符可读，监控读事件
                if(eventList_[idx].events & EPOLLIN){
                    handleNewConnection();
                }
            }else{
                //处理消息
                if(eventList_[idx].events & EPOLLIN){
                    handleMessage(fd);
                }
            }
        }
    }
}

void EventLoop::handleNewConnection()
{
    int peerfd = acceptor_.accept();
    addEpollFdRead(peerfd);
    TcpConnectionPtr conn(new TcpConnection(peerfd));
    conn->setConnectionCallback(onConnection_);
    conn->setMessageCallback(onMessage_);
    conn->setCloseCallback(onClose_);
    
    conns_.insert(std::make_pair(peerfd, conn));
    conn->handleConnectionCallback();
}


bool EventLoop::isConnectionClosed(int fd)
{
    int ret;
    do{
        char buff[1024];
        ret = recv(fd, buff, sizeof(buff), MSG_PEEK);
    }while(ret == -1 && errno == EINTR);

    return (ret == 0);
}

void EventLoop::handleMessage(int fd)
{
    bool isClosed = isConnectionClosed(fd);
    auto iter = conns_.find(fd);
    assert(iter != conns_.end());
    if(!isClosed)
    {
        iter->second->handleMessageCallback();
    }else{
        delEpollFdRead(fd);
        iter->second->handleCloseCallback();
        conns_.erase(iter);
    }
}

int EventLoop::createEpollFd()
{
    int ret = epoll_create1(0);
    if(-1 == ret){
        perror("epoll_create1");
    }
    return ret;

}

void EventLoop::addEpollFdRead(int fd)
{
    struct epoll_event evt;
    evt.data.fd = fd;
    evt.events = EPOLLIN;
    int ret = epoll_ctl(efd_, EPOLL_CTL_ADD, fd, &evt);
    if(-1 == ret)
    {
        perror("epoll_ctl");
    }
}

void EventLoop::delEpollFdRead(int fd)
{
    struct epoll_event evt;
    evt.data.fd = fd;
    int ret = epoll_ctl(efd_, EPOLL_CTL_DEL, fd, &evt);
    if(-1 == ret)
    {
        perror("epoll_ctl");
    }

}


void EventLoop::setConnectionCallback(const TcpConnectionCallback && cb)
{
    onConnection_ = std::move(cb);
}

void EventLoop::setMessageCallback(const TcpConnectionCallback && cb)
{
    onMessage_ = std::move(cb);
}

void EventLoop::setCloseCallback(const TcpConnectionCallback && cb)
{
    onClose_ = std::move(cb);
}
