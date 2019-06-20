#pragma once

#include <assert.h>
#include <string>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

namespace wd
{

class MyConf
{
public:
    explicit MyConf(const string &filepath);      //构造函数
    unordered_map<string, string> & getConfigMap();       //获取存放配置文件内容的map

private:
    string filepath_;               //配置文件路径
    unordered_map<string, string> configMap_;  //配置文件内容
};

}
