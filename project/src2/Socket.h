#ifndef __WD_SOCKET_H__
#define __WD_SOCKET_H__

namespace wd
{

class Socket
{
public:
	Socket();
	explicit
	Socket(int fd);

	int fd() const ;

	void shutdownWrite();

	~Socket();

private:
	int _fd;
};

}//end of namespace wd


#endif
