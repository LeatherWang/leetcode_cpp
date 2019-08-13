
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

void dfs(set<vector<int>>& res, vector<int>& nums, int index, vector<int> tmpVec)
{
    if(tmpVec.size() > 1)
        res.insert(tmpVec);
    for(int i = index; i<nums.size(); i++)
    {
        if(tmpVec.size() == 0 || nums[index-1] <= nums[i])
        {
            tmpVec.push_back(nums[i]);
            dfs(res, nums, i+1, tmpVec);
            tmpVec.pop_back();
        }
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums)
{
    set<vector<int>> resSet;
    dfs(resSet, nums, 0, vector<int>());
    return vector<vector<int>>(resSet.begin(), resSet.end());
}

int main()
{
    return 0;
}









