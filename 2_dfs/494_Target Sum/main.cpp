
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

using namespace std;

// sum(P) - sum(N) = target
// sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
// 2 * sum(P) = target + sum(nums)

int dfs(vector<int> &nums, int sum, int start)
{
    if(sum == 0)
        return 1;
    if(sum<0 || start==nums.size())
        return 0;
    int res  = 0;
    for(int i=start; i<nums.size(); i++)
    {
        res += dfs(nums, sum-nums[i], i+1);
    }
    return res;
}
int findTargetSumWays_1(vector<int>& nums, int S)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    sum +=S;
    if(sum&1)
        return 0;
    sum /= 2;
    sort(nums.begin(), nums.end());

    if(sum==0 && nums.front()==0)
    {
        int i=0;
        while(i<nums.size() && nums[i] == 0) i++;
        return pow(2, nums.size()-i);
    }
    else
        return dfs(nums, sum, 0);
}

//排名第一的代码
/**
   子集问题转化为求和问题， 再用 DP 解决
   sum(P)-sum(N) = target
   sum(P)+sum(N) = sum
   2 * sum(P)    = sum + target

   问题转为求和 sum(P) = (sum+target)/2

   状态定义：   设 f(i, j)为前i元素，和为 j 的可能情况
   转移方程：   f(i, j) = f(i-1, j) + f(i-1, j-val[i])
   边界条件：   f(i, 0) = 1
**/
int findTargetSumWays(vector<int>& nums, int S) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < S || (sum+S)&1) return 0;
    sum = (sum + S) / 2;

    vector<int>     dp(sum+1, 0);

    dp[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
        for (int v = sum; v >= nums[i]; v--) { //!@attention 注意循环条件
            dp[v] += dp[v-nums[i]];
        }
    }

    return dp[sum];
}

//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//所求解集为:
//[
//  [1, 7],
//  [1, 2, 5],
//  [2, 6],
//  [1, 1, 6]
//]
vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    int n = candidates.size();
    vector<int> dp(target+1, 0);
    dp[0] = 1;
    for(int i=0; i<n; i++)
    {
        for(int j=target; j>=candidates[i]; j--)
            dp[j] += dp[j-candidates[i]];
    }
    return vector<vector<int>>();
}

int main()
{
    //  binaryTreePaths();
    return 0;
}









