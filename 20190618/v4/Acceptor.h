 ///
 /// @file    Acceptor.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-07 15:22:19
 ///
 
#ifndef __WD_ACCEPTOR_H__
#define __WD_ACCEPTOR_H__

#include "InetAddress.h"
#include "Socket.h"

namespace wd
{

class Acceptor
{
public:
	Acceptor(unsigned short port);
	Acceptor(const string & ip, unsigned short port);
	void ready();

	int accept();
	int fd() const {	return _listensock.fd(); }
private:
	void setReuseAddr(bool on);
	void setReusePort(bool on);
	void bind();
	void listen();
private:
	InetAddress _addr;
	Socket _listensock;
};

}//end of namespace wd

#endif
