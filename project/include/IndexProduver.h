#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

namespace wd
{

class IndexProducer
{
public:
    explicit IndexProducer(
        const string& DicfilePath, const string& IndexfilePath);
    void read_dict();       //读取词典
    void build_index();     
    void store_index();
    void show_index();      //查看索引文件，测试用

private:
    string DicfilePath_;
    string IndexfilePath_;
    vector<pair<string, int> > vecDic_;
    map<string, set<int> > mapIndex_;
};

}
