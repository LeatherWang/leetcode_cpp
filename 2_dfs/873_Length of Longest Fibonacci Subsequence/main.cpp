
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
#include <queue>
#include <stack>

using namespace std;

//输入: [1,2,3,4,5,6,7,8]
//输出: 5
//解释:
//最长的斐波那契式子序列为：[1,2,3,5,8]

//输入: [1,3,7,11,12,14,18]
//输出: 3
//解释:
//最长的斐波那契式子序列有：
//[1,11,12]，[3,11,14] 以及 [7,11,18]
int lenLongestFibSubseq(vector<int>& A)
{
    int res = 0;
    set<int> setTmp(A.begin(), A.end());
    for(int i=0; i< A.size(); i++)
    {
        for(int j=i+1; j< A.size(); j++)
        {
            int a=A[i], b= A[j];
            int sum = a+b;
            int num = 0;
            while(setTmp.find(sum) != setTmp.end())
            {
                a = b;
                b = sum;
                sum = a+b;
                num++;
            }
            if(num)
                res = max(res, num+2);
        }
    }
    return res;
}

int lenLongestFibSubseq(vector<int>& A)
{
    unordered_map<int, int> m;
    int N = A.size(), res = 0;
    int dp[N][N];
    for (int j = 0; j < N; ++j)
    {
        m[A[j]] = j;
        for (int i = 0; i < j; ++i)
        {
            int k = m.find(A[j] - A[i]) == m.end() ? -1 : m[A[j] - A[i]];
            dp[i][j] = (A[j] - A[i] < A[i] && k >= 0) ? dp[k][i] + 1 : 2;
            res = max(res, dp[i][j]);
        }
    }
    return res > 2 ? res : 0;
}


int main()
{

    return 0;
}









