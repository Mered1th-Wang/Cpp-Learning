 ///
 /// @file    InetAddress.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-07 14:57:46
 ///
 
#ifndef __WD_INETADDRESS_H__
#define __WD_INETADDRESS_H__

#include <arpa/inet.h>
#include <string>
using std::string;

namespace wd
{

class InetAddress
{
public:
	explicit
	InetAddress(unsigned short port);
	InetAddress(const string & ip, unsigned short port);
	InetAddress(const struct sockaddr_in & addr);

	string ip() const;
	unsigned short port() const;
	struct sockaddr_in * getInetAddressPtr() {	return &_addr;	}
	
private:
	struct sockaddr_in _addr;
};

}//end of namespace wd

#endif
