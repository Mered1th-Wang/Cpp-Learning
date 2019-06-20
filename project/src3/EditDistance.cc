#include "EditDistance.h"

using namespace wd;

int EditDistance::work()
{
    	int m = word1.length();
        int n = word2.length();
        if(m == 0 || n == 0)
            return m == 0 ? n : m;
		// dp[i][j] --> the minimum number of edits to transform word1[0...i-1] to word2[0...j-1]
        vector<vector<int>>dp(m+1, vector<int>(n+1));
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
				//If both strings are empty
                if(i == 0 && j ==0) 
                    dp[i][j] = 0;
				// if first string is empty, only option is to insert all characters of second string into 
				// first one
                else if(i == 0)
                    dp[i][j] = j;
				// if second string is empty, only option is to delete all characters of first string
                else if(j == 0)
                    dp[i][j] = i;
				// if last character are same for both string, recur for the remaining
                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = 1 + min(min(
                                    dp[i][j-1],    // insert
                                    dp[i-1][j]),   // remove
                                    dp[i-1][j-1]); // replace
                }
            }
        }
	return dp[m][n];
}

