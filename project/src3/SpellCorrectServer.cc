#include "SpellCorrectServer.h"

using namespace wd;

SpellCorrectServer::SpellCorrectServer(const string & cfgFileName)
:conf_(cfgFileName), 
tcpServer_(conf_.getConfigMap().find("ip")->second,stoi(conf_.getConfigMap().find("port")->second)),
threadpool_(4, 10) 
{
    threadpool_.start();
}


void SpellCorrectServer::onConnection(const TcpConnectionPtr & conn)
{
   cout << conn->toString() << " has connected! " << endl;
   conn->send("welcome to server.");
}

void SpellCorrectServer::onMessage(const TcpConnectionPtr & conn)
{
	string msg = conn->receive();
	cout << ">> receive msg from client: " << msg << endl;
    
    MyDict * p = MyDict::createInstance();
    
    p->init(conf_.getConfigMap().find("dict")->second.c_str(),
            conf_.getConfigMap().find("index")->second.c_str());

    MyTask mytask(*p, msg, conn);
    threadpool_.addTask(std::bind(&MyTask::execute, mytask));
}

void SpellCorrectServer::onClose(const TcpConnectionPtr & conn)
{
    cout << conn->toString() << " has closed!" << endl;
}

using namespace placeholders;

void SpellCorrectServer::start()
{
    tcpServer_.setConnectionCallback(std::bind(&SpellCorrectServer::onConnection, this, _1));
    tcpServer_.setMessageCallback(std::bind(&SpellCorrectServer::onMessage, this, _1));
    tcpServer_.setCloseCallback(std::bind(&SpellCorrectServer::onClose, this, _1));

    tcpServer_.start();
}
