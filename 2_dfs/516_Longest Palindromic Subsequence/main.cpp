
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <math.h>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory.h>
#include <climits>
#include <sstream>
#include <set>

using namespace std;

//输入:
//"bbbab"
//输出:
//4
//一个可能的最长回文子序列为 "bbbb"

// dp[i][j]: the longest palindromic subsequence's length of substring(i, j),
// here i, j represent left, right indexes in the string
int longestPalindromeSubseq(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i=n-1; i>=0; i--)
    {
        dp[i][i] = 1; //临界状态，初始值
        for(int j= i+1; j<n; j++)
        {
            if(s[i] == s[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
        }
    }
    return dp[0][n-1];
}

int main()
{
    return 0;
}









