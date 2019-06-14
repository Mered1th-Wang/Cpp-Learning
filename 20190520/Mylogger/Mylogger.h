#ifndef __WD_MYLOGGER_H__
#define __WD_MYLOGGER_H__

#include <log4cpp/Category.hh>
#include <string>

using namespace std;
using namespace log4cpp;

namespace wd{


class Mylogger
{
public:
    static Mylogger * getInstance()
    {
        if(_pInstance == nullptr)
        {
            _pInstance = new Mylogger();
        }
        return _pInstance;
    }

    static void destroy()
    {
        if(_pInstance) delete _pInstance;
    }

    void error(const char * msg);
    void info(const char * msg);
    void warn(const char * msg);
    void debug(const char * msg);

private:
    Mylogger(); 
    ~Mylogger(); 

private:
    static Mylogger * _pInstance;
    Category & _mylogger;
};


}//end of namespace wd

#define prefix(msg) string(" [").append(__FILE__).append(":").append(__FUNCTION__)\
                                .append(":").append(to_string(__LINE__)).append("] ")\
                                .append(msg)

#define LogError(msg) wd::Mylogger::getInstance()->error(prefix("msg").c_str());
#define LogInfo(msg) wd::Mylogger::getInstance()->info(prefix("msg").c_str());
#define LogWarn(msg) wd::Mylogger::getInstance()->warn(prefix("msg").c_str());
#define LogDebug(msg) wd::Mylogger::getInstance()->debug(prefix("msg").c_str());

#endif
