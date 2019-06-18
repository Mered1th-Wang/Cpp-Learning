#pragma once

#include "SplitTool.h"

#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <dirent.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

namespace wd
{

class DictProducer
{
public:
    explicit DictProducer(const string& dir, const string & filepath); 
    //DictProducer(const string& dir, SplitTool *splitTool);//专为中文处理
    void build_dict();
    //void build_cn_dict();
    void store_dict(); //将词典写入文件
    void show_files() const;    //查看文件路径，测试用
    void show_dict() const;     //查看词典，测试用
    
    void get_files();           //获取文件的绝对路径
    //void push_dict(const string & word);    //存储单词

private:
    string dir_;
    string filepath_;
    vector<string> files_;
    map<string, int> dict_;
};

}
