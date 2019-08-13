
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
#include <unordered_set>

using namespace std;



void backTracking(vector<int>& candidates, vector<vector<int>> &res, vector<int> tmpVec, int remain, int start)
{
    if(remain < 0)
        return;
    if(remain == 0)
    {
        res.push_back(tmpVec);
        return;
    }

    for(int i=start; i< candidates.size(); i++)
    {
        if(i > start && candidates[i] == candidates[i-1])
            continue;
        tmpVec.push_back(candidates[i]);
        backTracking(candidates, res, tmpVec, remain - candidates[i], i+1);
        tmpVec.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    vector<vector<int>> res;
    vector<int> tmpVec;
    sort(candidates.begin(), candidates.end());
    backTracking(candidates, res, tmpVec, target, 0);
    return res;
}

int main()
{
    return 0;
}









