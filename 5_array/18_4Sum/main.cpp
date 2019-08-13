
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


vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> res;
    if(nums.size()<4) return res;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size();)
    {
        for(int j=i+1; j< nums.size(); )
        {
            int k = j+1;
            int l = nums.size()-1;
            for(;k < l;)
            {
                int sum = nums[i]+nums[j]+nums[k]+nums[l];
                if(sum == target)
                {
                    cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<" "<<nums[l]<<endl;
                    res.push_back(vector<int>{nums[i],nums[j],nums[k],nums[l]});
                    while(nums[k] == nums[++k]);
                    while(nums[l] == nums[--l]);
                }
                else if(sum > target)
                    l--;
                else
                    k++;
            }
            while(nums[j] == nums[++j]);
        }
        while(nums[i] == nums[++i]);
    }
    return res;
}
//给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0
//满足要求的四元组集合为：
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//]
int main()
{
    vector<int> myvec{1, 0, -1, 0, -2, 2};
    fourSum(myvec, 0);
    return 0;
}









