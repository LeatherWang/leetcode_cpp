
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

int dfs(vector<int>& nums, vector<int> &midRes, int index)
{
    if(index >= nums.size())
        return 0;

    if(midRes[index] != -1)
        return midRes[index];

    int equalIndex = index+1;
    while(equalIndex < nums.size() && nums[index] == nums[equalIndex++]);

    int a1=0, a2=0;
    if(equalIndex < nums.size() && ((nums[index]+1) < nums[equalIndex]))
    {
        a1 = a2 = nums[index]*(equalIndex-index) + dfs(nums, midRes, equalIndex);
    }
    else
    {
        a1 = dfs(nums, midRes, equalIndex);
        int nextGroup = equalIndex+1;
        while(nextGroup < nums.size() && nums[equalIndex] == nums[nextGroup++]); //! @attention
        a2 = nums[index]*(equalIndex-index) + dfs(nums, midRes, nextGroup);
    }

    return midRes[index]=max(a1, a2);
}

int deleteAndEarn(vector<int>& nums)
{
    vector<int> midRes(nums.size(), -1);
    sort(nums.begin(), nums.end());
    return dfs(nums, midRes, 0);
}

// 排名第二的算法
int deleteAndEarn(vector<int>& nums) {
    vector<int>sums(10001,0);
    for(int num:nums)
        sums[num] += num;
    for(int i=2;i<10001;i++)
    {
        sums[i]=max(sums[i-1],sums[i-2]+sums[i]);
    }
    return sums[10000];
}

// 排名第一的算法
int deleteAndEarn(vector<int>& nums)
{
    int len = nums.size();
    if (!len)
        return 0;
    vector<int> cnt(10005);
    vector<int> num;
    for (int i = 0; i < len; i++) cnt[nums[i]]++;
    for (int i = 0; i < 10005; i++) if (cnt[i]) num.push_back(i);
    int n = num.size();
    vector<int> dp(n + 1);
    dp[1] = num[0] * cnt[num[0]];
    for (int i = 2; i <= n; i++)
    {
        int before = i - 1;
        if (num[i-1] - 1>num[i - 2])
            dp[i] = dp[before] + num[before] * cnt[num[before]]; //如果非连续
        else
            dp[i] = max(dp[before], dp[before-1]+num[before]*cnt[num[before]]); //如果是连续的
    }
    return dp[n];
}

int main()
{
    return 0;
}









