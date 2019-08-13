
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

void backTracking(vector<int>& nums, vector<vector<int>> &res, vector<bool>& visited , vector<int>& tmpVec)
{
    if(tmpVec.size() == nums.size())
        res.push_back(tmpVec);
    else
    {
        for(int i=0; i<nums.size(); i++)
        {
            if(visited[i] || (i>0 && nums[i]==nums[i-1] && !visited[i-1])) //保证顺序，以前一后，就不会出现重复
                continue;
            visited[i] = true;
            tmpVec.push_back(nums[i]);
            backTracking(nums, res, visited, tmpVec);
            tmpVec.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    vector<vector<int>>  res;
    vector<int> tmpVec;
    vector<bool> visited(nums.size(), false);
    sort(nums.begin(), nums.end());
    backTracking(nums, res, visited, tmpVec);
    return res;
}

int main()
{
    return 0;
}









