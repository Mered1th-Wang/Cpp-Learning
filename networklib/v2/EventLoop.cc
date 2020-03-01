#include "EventLoop.h" 
#include "Acceptor.h"
#include "TcpConnection.h"

#include <assert.h>

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

EventLoop::EventLoop(Acceptor & acceptor)
: _efd(createEpollFd())
, _acceptor(acceptor)
, _eventList(1024)
, _isLooping(false)
{
	addEpollFdRead(_acceptor.fd());
}

void EventLoop::loop()
{
	_isLooping = true;
	while(_isLooping) {
		waitEpollFd();
	}
}

void EventLoop::unloop()
{
	if(_isLooping) 
		_isLooping = false;
}

void EventLoop::waitEpollFd()
{
	int nready;
	do {
		nready = epoll_wait(_efd, &*_eventList.begin(), _eventList.size(), 5000);
	}while(nready == -1 && errno == EINTR);

	if(nready == -1) {
		perror("epoll_wait");
		return;
	} else if(nready == 0) {
		cout << ">> epoll_wait timeout!" << endl;
	} else {
		if(nready == _eventList.size()) {
			_eventList.resize(2 * nready);
		}

		for(int idx = 0; idx != nready; ++idx) {
			int fd = _eventList[idx].data.fd;
			if(fd == _acceptor.fd()) {
				//处理新连接
				if(_eventList[idx].events & EPOLLIN) {
					handleNewConnection();
				}
			}else {
				//处理消息
				if(_eventList[idx].events & EPOLLIN) {
					handleMessage(fd);
				}
			}
		}
	}
}

void EventLoop::handleNewConnection()
{
	int peerfd = _acceptor.accept();
	addEpollFdRead(peerfd);
	TcpConnectionPtr conn(new TcpConnection(peerfd));
	conn->setConnectionCallback(_onConnection);
	conn->setMessageCallback(_onMessage);
	conn->setCloseCallback(_onClose);

	_conns.insert(std::make_pair(peerfd, conn));

	conn->handleConnectionCallback();
}

void EventLoop::handleMessage(int fd)
{
	bool isClosed = isConnectionClosed(fd);
	auto iter = _conns.find(fd);
	assert(iter != _conns.end());//运行时断言

	if(!isClosed) {
		iter->second->handleMessageCallback();
	} else {
		delEpollFdRead(fd);
		iter->second->handleCloseCallback();
		_conns.erase(iter);
	}
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
	
int EventLoop::createEpollFd()
{
	int ret = ::epoll_create1(0);
	if(ret == -1) {
		perror("epoll_create1");
	}
	return ret;
}

void EventLoop::addEpollFdRead(int fd)
{
	struct epoll_event evt;
	evt.data.fd = fd;
	evt.events = EPOLLIN;
	int ret = epoll_ctl(_efd, EPOLL_CTL_ADD, fd, &evt);
	if(-1 == ret) {
		perror("epoll_ctl");
	}
}

void EventLoop::delEpollFdRead(int fd)
{
	struct epoll_event evt;
	evt.data.fd = fd;
	int ret = epoll_ctl(_efd, EPOLL_CTL_DEL, fd, &evt); 
	if(-1 == ret) {
		perror("epoll_ctl");
	}
}
}//end of namespace wd
