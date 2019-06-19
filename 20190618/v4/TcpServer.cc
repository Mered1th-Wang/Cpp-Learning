 ///
 /// @file    TcpServer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-08 15:07:04
 ///
 
#include "TcpServer.h"

namespace wd
{
TcpServer::TcpServer(const string & ip, unsigned short port)
: _acceptor(ip, port)
, _loop(_acceptor)
{}

void TcpServer::start()
{
	_acceptor.ready();
	_loop.loop();
}

void TcpServer::setConnectionCallback(TcpConnectionCallback && cb)
{	_loop.setConnectionCallback(std::move(cb));	}

void TcpServer::setMessageCallback(TcpConnectionCallback && cb)
{	_loop.setMessageCallback(std::move(cb));	}

void TcpServer::setCloseCallback(TcpConnectionCallback && cb)
{	_loop.setCloseCallback(std::move(cb));	}

}//end of namespace wd
