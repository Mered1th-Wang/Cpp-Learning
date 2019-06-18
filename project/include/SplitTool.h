#pragma once

#include <string>
#include <vector>

using namespace std;

namespace wd
{

class SplitTool
{
public:
    SplitTool();  
    virtual ~SplitTool();
    virtual vector<string> cut(const string& sentence) = 0;
};

}
