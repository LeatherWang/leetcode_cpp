
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

int lengthOfLIS(vector<int>& nums)
{
    int n = nums.size();
    vector<int> dp(nums.size(), 1);
    for(int i=0; i< n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(nums[j] < nums[i])
                dp[i] = max(dp[j]+1, dp[i]);
        }
    }

    int res = 0;
    for(int i=0; i< n; i++)
        if(dp[i] > res)
            res = dp[i];
    return res;
}


int main()
{
    return 0;
}









