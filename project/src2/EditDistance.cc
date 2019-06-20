#include "EditDistance.h"

using namespace wd;

int EditDistance::work()
{
    int lena = a_.size();
    int lenb = a_.size();
    for(int i=1; i<=lena; i++) dp[i][0] = i;
    for(int j=1; j<=lenb; j++) dp[0][j] = j;
    for(int i=1; i<=lena; i++)
        for(int j=1; j<=lenb; j++)
            if(a_[i-1]==b_[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;
    return dp[lena][lenb];
}

