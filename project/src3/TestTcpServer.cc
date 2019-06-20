#include "SpellCorrectServer.h"

using namespace wd;

MyDict* MyDict::pInstance_ = new MyDict();  //饱汉模式

int main(void)
{
    SpellCorrectServer server("/home/wj/C++/project/conf");
    server.start();

    return 0;
}
