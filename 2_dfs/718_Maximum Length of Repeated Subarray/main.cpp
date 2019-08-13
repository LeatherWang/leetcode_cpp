
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

int findLength(vector<int>& A, vector<int>& B)
{
    int res=0;
    int An = A.size(), Bn = B.size();
    vector<vector<int>> dp(An+1, vector<int>(Bn+1, 0));
    for(int i=1; i<=An; i++)
    {
        for(int j=1; j<=Bn; j++)
        {
            if(A[i-1] == B[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                res = max(res, dp[i][j]);
            }
        }
    }
    return res;
}

// 排名第三的算法，如果把A.size()和B.size()提前算出来，就排名第一了
int findLength(vector<int>& A, vector<int>& B) {
    int ret = 0;
    vector<int> dp = vector<int>(B.size() + 1, 0);
    for (int i = 0; i < A.size(); ++i){
        for (int j = B.size() - 1; j >= 0; --j){
            if (A[i] == B[j]){
                dp[j + 1] = dp[j] + 1;
                ret = max(ret, dp[j + 1]);
            }
            else{
                dp[j + 1] = 0;
            }
        }
    }
    return ret;
}

int main()
{

    return 0;
}









