
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

void backTracking(vector<int>& nums, vector<vector<int>> &res, unordered_set<int>& tmpSet, vector<int>& tmpVec)
{
    if(tmpVec.size() == nums.size())
        res.push_back(tmpVec);
    else
    {
        for(int i=0; i<nums.size(); i++)
        {
            if(tmpSet.find(nums[i]) != tmpSet.end())
                continue;
            tmpSet.insert(nums[i]);
            tmpVec.push_back(nums[i]);
            backTracking(nums, res, tmpSet, tmpVec);
            tmpSet.erase(tmpSet.find(nums[i]));
            tmpVec.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>>  res;
    unordered_set<int> tmpSet;
    vector<int> tmpVec;
    backTracking(nums, res, tmpSet, tmpVec);
    return res;
}

int main()
{
    return 0;
}









