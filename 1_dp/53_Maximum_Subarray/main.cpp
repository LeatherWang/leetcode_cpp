
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
int maxSubArray_myself(vector<int>& nums)
{
    int maxSubSum=INT_MIN, tempSum=0;
    for(int i=0; i < nums.size(); i++)
    {
        tempSum +=nums[i];

//        if(tempSum > maxSubSum)
//        {
//            maxSubSum = tempSum;
//        }
        maxSubSum = max(tempSum, maxSubSum);

        if(tempSum < 0) //! 负数对求和增加无益，置零
            tempSum = 0;
    }
    return maxSubSum;
}
// 输入: [-2,1,-3,4,-1,2,1,-5,4],
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

// 分而治之
int dfs(vector<int> &nums, int begin, int end)
{
    if(begin == end)
        return nums[begin];

    int mid = (begin+end)/2;
    int tmp = INT_MIN, sum=0, res=0; //! `tmp = INT_MIN`是保证，如果nums序列全部都是负数时，要至少取一个值，以区分分治得到的左右子序列
    for(int i=mid; i>=begin; i--)
    {
        sum +=nums[i];
        tmp = max(tmp, sum);
    }
    res += tmp;
    tmp = INT_MIN;
    sum = 0;
    for(int i=mid+1; i<=end; i++)
    {
        sum +=nums[i];
        tmp = max(tmp, sum);
    }
    res += tmp;

    return max(res, max(dfs(nums, begin, mid), dfs(nums, mid+1, end)));
}

int maxSubArray(vector<int>& nums)
{
    if(nums.empty())
        return 0;
    return dfs(nums, 0, nums.size()-1);
}

int main()
{
    vector<int> myvec{-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(myvec)<<endl;
    return 0;
}









