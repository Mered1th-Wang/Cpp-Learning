#include "Threadpool.h"
#include "TcpServer.h"
#include "EditDistance.h"
#include "MyTask.h"
#include "MyDict.h"
#include "MyConf.h"
#include "SpellCorrectServer.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
using namespace wd;

MyDict* MyDict::pInstance_ = new MyDict();  //饱汉模式

int main(void)
{
    SpellCorrectServer server("/home/wj/C++/project/conf");
    server.start();

    return 0;
}
