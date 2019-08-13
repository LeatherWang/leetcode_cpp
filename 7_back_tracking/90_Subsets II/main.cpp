
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

using namespace std;

void backTracking(vector<int>& nums, vector<vector<int>> &res, vector<int>& tmpVec, int start)
{
    res.push_back(tmpVec);

    for(int i=start; i<nums.size(); i++)
    {
        if(i>start && nums[i]==nums[i-1])
            continue;
        tmpVec.push_back(nums[i]);
        backTracking(nums, res, tmpVec, i+1);
        tmpVec.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    vector<vector<int>> res;
    vector<int> tmpVec;
    sort(nums.begin(), nums.end());
    backTracking(nums, res, tmpVec, 0);
    return res;
}
int main()
{
    return 0;
}









