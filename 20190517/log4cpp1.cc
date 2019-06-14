#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
using namespace log4cpp;

#include <iostream>

using namespace std;

int main()
{
    Category & root = Category::getRoot(); 
    // 创建对象root，调用getRoot()

    OstreamAppender* pOstreamAppender = new OstreamAppender("OstreamAppender", &cout);
    //构造函数OstreamAppender(const std::string &name, std::ostream *stream);
    //创建输出源
    
    pOstreamAppender->setLayout(new BasicLayout());
    //设置输出源的Layout


    root.setAppender(pOstreamAppender);
    root.setPriority(Priority::DEBUG); 

    root.debug("this is a debug message.");
    root.error("this is an err message.");
    root.emerg("this is an emerg message.");
    Category::shutdown();
    
    return 0;
}
