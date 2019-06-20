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
        statistic(indexTable[string(1, queryWord_[idx])]);
   }
}

void MyTask::statistic(set<int> & iset)
{
    auto dicTable = dic_.getDict();
    MyResult tmp;
    for(size_t idx = 0; idx != iset.size(); ++idx)
    {
        tmp.word_ = dicTable[idx].first;
        tmp.iFreq_ = dicTable[idx].second;
        tmp.iDist_ = distance(dicTable[idx].first);
        resultQue_.push(tmp);
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
}


}
