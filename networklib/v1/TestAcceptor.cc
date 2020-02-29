#include "Acceptor.h"
#include "TcpConnection.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

using namespace wd;

int main(void)
{
	wd::Acceptor acceptor("192.168.1.107", 8888);
	acceptor.ready();
	
	wd::TcpConnection conn(acceptor.accept());
	cout << conn.toString() << " has connected!" << endl;
	conn.send("welcome to server.");
	printf("> pls client data:\n");
	cout << conn.receive() << endl;

	return 0;
}
