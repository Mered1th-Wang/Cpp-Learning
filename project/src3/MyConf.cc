#include "MyConf.h"

using namespace wd;
using namespace std;

MyConf::MyConf(const string &filepath)
    :   filepath_(filepath)
{
    ifstream ifs(filepath_);
    string s1, s2;
    while(ifs >> s1 >> s2)
    {
         configMap_.insert(make_pair(s1, s2));
    }
}

unordered_map<string, string>& MyConf:: getConfigMap()
{
    return configMap_;
}

