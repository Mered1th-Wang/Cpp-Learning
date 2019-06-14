#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>

#include <iostream>

using namespace std;
using namespace log4cpp;

//步骤
//1. 创建ostreamAppender
//2. 设计patternLayout或直接使用Basic
//3. ostreamAppender调用setLayout将格式化

//http://log4cpp.sourceforge.net/api/hierarchy.html

int main()
{
    PatternLayout * patternLayout1 = new PatternLayout();
    patternLayout1->setConversionPattern("%d [%p] %m%n");

    PatternLayout * patternLayout2 = new PatternLayout();
    patternLayout2->setConversionPattern("%d [%p] %m%n");

    PatternLayout * patternLayout3 = new PatternLayout();
    patternLayout3->setConversionPattern("%d [%p] %m%n");

    OstreamAppender * ostreamAppender = new log4cpp::OstreamAppender("OstreamAppender", &cout);
    ostreamAppender->setLayout(patternLayout1);

    FileAppender * fileAppender = new FileAppender("fileAppender", "a.log");
    fileAppender->setLayout(patternLayout2);

    RollingFileAppender * rollingFileAppender = 
        new log4cpp::RollingFileAppender(
                                         "rollingFileAppender",
                                         "rolling.log",
                                         1000,
                                         3);
 
 //   rollingFileAppender->setMaximumFileSize(40000);
 //   rollingFileAppender->setMaxBackupIndex(3);
 //   rollingFileAppender->getAppender("rolling.log");

 //   log4cpp::RollingFileAppender::RollingFileAppender   (   const std::string &       name,
 //                                                           const std::string &       fileName,
 //                                                           size_t    maxFileSize = 10 *1024 *1024,
 //                                                           unsigned int      maxBackupIndex = 1,
 //                                                           bool      append = true,
 //                                                           mode_t    mode = 00644
 //                                                           )   


    rollingFileAppender->setLayout(patternLayout3);

    Category & myRecord = Category::getRoot().getInstance("mycategory");
    myRecord.setAppender(ostreamAppender);
    myRecord.addAppender(fileAppender);
    myRecord.addAppender(rollingFileAppender);
    myRecord.setPriority(Priority::DEBUG);

    for(int idx = 0; idx != 50; ++idx)
    {
        myRecord.emerg("this is an emerg message");//方法本身代表的就是这一条日志的级别
        myRecord.fatal("this is a fatal message");
        myRecord.alert("this is an alert message");
        myRecord.crit("this is a crit message");
        myRecord.warn("this is a warn message");
        myRecord.error("this is an error message");
        myRecord.notice("this is a notice message");
        myRecord.info("this is an info message");
        myRecord.debug("this is a debug message");
    }

    Category::shutdown();
    return 0;
}

