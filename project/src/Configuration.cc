#include "../include/Configuration.h"

using namespace wd;
using namespace std;

Configuration::Configuration(const string &filepath)
    :   filepath_(filepath)
{
    ifstream ifs(filepath_);
    string s1, s2;
    while(ifs >> s1 >> s2)
    {
         configMap_.insert(make_pair(s1, s2));
    }
}

unordered_map<string, string>& Configuration:: getConfigMap()
{
    return configMap_;
}

void Configuration::print()
{
    for(auto it = configMap_.begin(); it != configMap_.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
}
