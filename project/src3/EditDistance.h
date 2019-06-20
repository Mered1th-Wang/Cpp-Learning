#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

namespace wd
{

class EditDistance
{
public:
    EditDistance(const string& a, const string& b)
        : word1(a), word2(b)
    {}

    int work();

private:
    string word1;
    string word2;
    int dp[1010][1010];
};

}
