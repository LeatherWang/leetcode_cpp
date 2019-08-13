
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

// 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

void backTracking(vector<vector<int>> &res, vector<int> tmpVec, int remain, int start, int k)
{
    if(k<0)
        return;
    else if(k==0)
    {
        if(remain == 0)
            res.push_back(tmpVec);
        return;
    }

    for(int i=start; i<= 9; i++)
    {
        tmpVec.push_back(i);
        backTracking(res, tmpVec, remain-i, i+1, k-1);
        tmpVec.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> res;
    vector<int> tmpVec;
    backTracking(res, tmpVec, n, 1, k);
    return res;
}

int main()
{
    return 0;
}









