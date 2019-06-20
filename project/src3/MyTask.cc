#include "MyTask.h"
#include "EditDistance.h"

namespace wd
{

void MyTask::execute()
{
    queryIndexTable();
    response();
}

void MyTask::queryIndexTable()
{
   for(size_t idx = 0; idx != queryWord_.size(); ++idx)
   {
        auto indexTable = dic_.getIndexTable();
        string ch = string(1,queryWord_[idx]); 
        statistic(indexTable[string(1, queryWord_[idx])]);
   }
}

void MyTask::statistic(set<int> & iset)
{
    auto dicTable = dic_.getDict();
    MyResult tmp;
    
    for(auto iter = iset.begin(); iter != iset.end(); ++iter)
    {
        tmp.word_ = dicTable[*iter].first; 
        tmp.iFreq_= dicTable[*iter].second; 
        tmp.iDist_ = distance(dicTable[*iter].first);
        if(tmp.iDist_ < 3) {
            resultQue_.push(tmp);
        }
    }
}

int MyTask::distance(const string & rhs)
{
    EditDistance editdis(queryWord_, rhs);
    return editdis.work();
}

void MyTask::response()
{
	conn_->sendInLoop(resultQue_.top().word_);
    
    priority_queue<MyResult, vector<MyResult>, MyCompare> temp;
    resultQue_.swap(temp); //清空队列
}

}
