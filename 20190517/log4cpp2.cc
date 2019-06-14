#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>

#include <iostream>

using namespace std;
using namespace log4cpp;

//步骤
//1. 创建ostreamAppender
//2. 设计patternLayout或直接使用Basic
//3. ostreamAppender调用setLayout将格式化
int main()
{
    PatternLayout * patternLayout = new PatternLayout();
    patternLayout->setConversionPattern("%d [%p] %m%n");
    
    OstreamAppender * ostreamAppender = new log4cpp::OstreamAppender("OstreamAppender", &cout);
    ostreamAppender->setLayout(patternLayout);

    Category & myRecord = Category::getRoot().getInstance("mycategory");
    myRecord.setAppender(ostreamAppender);
    myRecord.setPriority(Priority::DEBUG);

    myRecord.emerg("this is an emerg messsage");

    Category::shutdown();
    return 0;
}

