#include "Mylogger.h"
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>

using namespace std;

namespace wd
{

Mylogger * Mylogger::_pInstance = nullptr;

Mylogger::Mylogger():_mylogger(Category::getRoot().getInstance("mylogger"))
    {
        PatternLayout * ptn1 = new PatternLayout();
        ptn1->setConversionPattern("%d [%c] [%p] %m%n");

        PatternLayout * ptn2 = new PatternLayout();
        ptn2->setConversionPattern("%d [%c] [%p] %m%n");

        OstreamAppender * ostreamAppender = new OstreamAppender("ostreamAppender", &cout);
        ostreamAppender->setLayout(ptn1);

        FileAppender * fileAppender = new FileAppender("fileAppender", "log");
        fileAppender->setLayout(ptn2);

        _mylogger.addAppender(ostreamAppender);
        _mylogger.addAppender(fileAppender);
        _mylogger.setPriority(Priority::DEBUG);

        cout << "Mylogger()" << endl;
    }

Mylogger::~Mylogger()
{
    Category::shutdown();
    cout << "~Mylogger()" << endl;
}

void Mylogger::error(const char * msg)
{
    _mylogger.error(msg);
}

void Mylogger::info(const char * msg)
{
    _mylogger.info(msg);
}
void Mylogger::warn(const char * msg)
{
    _mylogger.warn(msg);
}
void Mylogger::debug(const char * msg)
{
    _mylogger.debug(msg);
}

}
