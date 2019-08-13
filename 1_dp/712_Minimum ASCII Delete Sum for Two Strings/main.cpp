
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

using namespace std;
int minimumDeleteSum(string s1, string s2)
{
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int j = 1; j <= n; j++)
        dp[0][j] = dp[0][j-1]+s2[j-1];
    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i-1][0]+s1[i-1];
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1]);
        }
    }
    return dp[m][n];
}

// 解法一
int minimumDeleteCharNum(string s1, string s2)
{
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int j = 1; j <= n; j++)
        dp[0][j] = dp[0][j-1]+1;
    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i-1][0]+1;
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
        }
    }
    return dp[m][n];
}

// 解法二:求最大公共字符串长度
int minDistance(string word1, string word2)
{
    int n1 = word1.size(), n2 = word2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return n1 + n2 - 2 * dp[n1][n2];
}

int main()
{
    cout<<minimumDeleteSum("delete","leet")<<endl;
    return 0;
}









