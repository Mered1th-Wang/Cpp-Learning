#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>

#include <iostream>

using namespace std;
using namespace log4cpp;

class Mylogger
{
public:
    static Mylogger* getInstance()
    {
        if(nullptr == _pInstance)
        {
            _pInstance = new Mylogger();
        }
        return _pInstance;
    }
    static void destroy()
    {
        if(_pInstance)
        {
            delete _pInstance;
        }
    }

private:
    Mylogger():
        _ostreamAppender(new OstreamAppender("OstreamAppender", &cout))
        ,_rollingFileAppender(new RollingFileAppender("RollingFileAppender", "log", 10 * 1024 * 1024, 3))
        ,_patternLayout1(new PatternLayout())
        ,_patternLayout2(new PatternLayout())
        ,_root(Category::getRoot().getInstance("MyCategory"))
    {   
        _patternLayout1->setConversionPattern("%d{%H:%M:%S} [%p] %c %x :%m%n");
        _patternLayout2->setConversionPattern("%d{%H:%M:%S} [%p] %c %x :%m%n");
        _rollingFileAppender->setLayout(_patternLayout1);
        _ostreamAppender->setLayout(_patternLayout2);
        _root.addAppender(_ostreamAppender);
        _root.addAppender(_rollingFileAppender);
        _root.setPriority(Priority::DEBUG);
        cout << "Mylogger()" << endl;
    }
    ~Mylogger()
    {
        Category::shutdown();
        cout << "~Mylogger()" << endl;
    }
public:
    void warn(const char *msg)
    {
        stringstream oss;
        oss << msg << "     Line: " << __LINE__ << "     function: " << __FUNCTION__;
        string res = oss.str();
        _root.notice(res);
    }
    void error(const char * msg)
    {
        stringstream oss;
        oss << msg << "     Line: " << __LINE__ << "     function: " << __FUNCTION__;
        string res = oss.str();
        _root.error(res);
    }
    void debug(const char * msg)
    {
        stringstream oss;
        oss << msg << "     Line: " << __LINE__ << "     function: " << __FUNCTION__;
        string res = oss.str();
        _root.debug(res);
    }
    void info(const char * msg)
    {
        stringstream oss;
        oss << msg << "     Line: " << __LINE__ << "     function: " << __FUNCTION__;
        string res = oss.str();
        _root.info(res);
    }
private:
    static Mylogger* _pInstance;
    OstreamAppender * _ostreamAppender;
    RollingFileAppender *_rollingFileAppender;
    PatternLayout *_patternLayout1;
    PatternLayout *_patternLayout2;
    Category & _root;
};

Mylogger* Mylogger::_pInstance = nullptr;

int main()
{
    Mylogger * log = Mylogger::getInstance();
    log->warn("hello");
    log->info("hello");
    log->error("hello");
    log->debug("hello");
    log->destroy();
    return 0;
}
