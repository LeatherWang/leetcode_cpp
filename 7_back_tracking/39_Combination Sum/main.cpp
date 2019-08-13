
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
// 我自己的方法，很慢，beat50%
void dfs(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int> tmpVec, int index)
{
    if(index >= candidates.size())
        return;
    if(target<0)
        return;
    if(target == 0)
    {
        res.push_back(tmpVec); //! @attention 到达边界条件，之后要return啊！！不然又走一边
        return;
    }

    for(;;)
    {
        dfs(candidates, target, res, tmpVec, index+1);
        target -=candidates[index];
        if(target >= 0)
            tmpVec.push_back(candidates[index]);
        else
            break;
    }
}

void backTracking(vector<int>& candidates, vector<vector<int>> &res, vector<int> tmpVec, int remain, int start)
{
    if(remain < 0)
        return;
    if(remian == 0)
    {
        res.push_back(tmpVec);
        return;
    }

    for(int i=start; i< candidates.size(); i++)
    {
        tmpVec.push_back(candidates[i]);
        backTracking(candidates, res, tmpVec, remain - candidates[i], i); //not i+1 because we can reuse same elements
        tmpVec.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> res;
    dfs(candidates, target, res, vector<int>(), 0);
    return res;
}

int main()
{
    return 0;
}









