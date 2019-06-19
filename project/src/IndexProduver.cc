#include "../include/IndexProduver.h"

using namespace wd;


IndexProducer::IndexProducer(const string& DicfilePath, const string& IndexfilePath)
    : DicfilePath_(DicfilePath),
      IndexfilePath_(IndexfilePath)
{}

void IndexProducer::read_dict()
{
   ifstream ifs(DicfilePath_);
   string word;
   int location = 0, num;
   while(ifs >> word >> num)
   {
       vecDic_.push_back(make_pair(word, location++));
   }
   ifs.close();
}

void IndexProducer::build_index()
{
    for(char ch = 'a'; ch <= 'z'; ++ch)
    {
        for(size_t idx = 0; idx != vecDic_.size(); ++idx)
        {
            if(vecDic_[idx].first.find(ch) != string::npos)
            {
                //cout << string(ch, 1) << endl;
                mapIndex_[string(1, ch)].insert(vecDic_[idx].second);
            }
        }
    }
}

void IndexProducer::store_index()
{
    ofstream ofs;
    ofs.open(IndexfilePath_);
    for(auto iter = mapIndex_.begin(); iter != mapIndex_.end(); ++iter)
    {
        ofs << iter->first << endl;
        for(auto idx = iter->second.begin(); idx != iter->second.end(); ++idx)
        {
            ofs << *idx << " ";  
        }
        ofs << endl;
    }
    ofs.close();
}

void IndexProducer::show_index()
{
    for(auto iter = mapIndex_.begin(); iter != mapIndex_.end(); ++iter)
    {
       cout << iter->first << endl;
       for(auto idx = iter->second.begin(); idx != iter->second.end(); ++idx)
       {
           cout << *idx << " ";  
       }
       cout << endl;
    }
}
