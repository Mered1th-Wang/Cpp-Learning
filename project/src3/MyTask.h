#pragma once

#include "MyDict.h"
#include "TcpConnection.h"

#include <string>
#include <queue>
#include <set>
#include <memory>


using namespace std;

namespace wd
{

struct MyResult
{
    string word_;   //候选词
    int iFreq_;     //词频
    int iDist_;     //与查询词的最小距离
};

class MyCompare
{
public:
    bool operator()(const MyResult &lhs, const MyResult &rhs)
    {
        if(lhs.iDist_ != rhs.iDist_) return lhs.iDist_ > rhs.iDist_;
        else if(lhs.iFreq_ != rhs.iFreq_) return lhs.iFreq_ < rhs.iFreq_;
        else return lhs.word_ > rhs.word_;
    }
};

class MyTask
{
public:
    MyTask(MyDict & dic, const string& queryWord, const TcpConnectionPtr & conn)
        : dic_(dic), conn_(conn) 
    {
        queryWord_ = queryWord.substr(0,queryWord.size()-1);
    }
    
    void execute();                     //执行查询
    void queryIndexTable();             //查询索引
    void statistic(set<int> & iset);    //进行计算
    int distance(const string & rhs);   //计算最小编辑距离
    void response();                    //更新Cache

private:
    MyDict & dic_;
    string queryWord_;
    priority_queue<MyResult, vector<MyResult>, MyCompare> resultQue_;
    TcpConnectionPtr conn_;
};


}
