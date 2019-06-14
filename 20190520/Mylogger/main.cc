#include "Mylogger.h"
#include <iostream>

using namespace std;

void test0()
{
    wd::Mylogger::getInstance()->error("msg");
    wd::Mylogger::getInstance()->info("msg");
    wd::Mylogger::getInstance()->warn("msg");
    wd::Mylogger::getInstance()->debug("msg");
}

void test1()
{
    wd::Mylogger::getInstance()->error(prefix("error message").c_str());
}

void test2()
{
    LogError("error msg");
    LogInfo("info msg");
    LogWarn("warn msg");
    LogDebug("debug msg");
}

int main()
{
    //test0();
    //test1();
    test2();
    
    wd::Mylogger::destroy();
    return 0;
}
