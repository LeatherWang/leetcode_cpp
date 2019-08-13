
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

void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmpVec, int index)
{
    if(index >= nums.size())
    {
        res.push_back(tmpVec);
        return;
    }

    dfs(nums, res, tmpVec, index+1);
    tmpVec.push_back(nums[index]);
    dfs(nums, res, tmpVec, index+1);
    tmpVec.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> res;
    //vector<int> tmpVec;
    //dfs(nums, res, tmpVec, 0);

    res.push_back(vector<int>());
    for(int i=0; i< nums.size(); i++)
    {
        int size = res.size();
        for(int j=0; j<size; j++)
        {
            res.push_back(res[j]);
            res.back().push_back(nums[i]);
        }
    }

    return res;
}

int main()
{
    return 0;
}









