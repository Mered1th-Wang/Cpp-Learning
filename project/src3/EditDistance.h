#pragma once
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

namespace wd
{

class EditDistance
{
public:
    EditDistance(const string& a, const string& b)
        : a_(a), b_(b)
    {}

    int work();

private:
    string a_;
    string b_;
    int dp[1010][1010];
};

}
