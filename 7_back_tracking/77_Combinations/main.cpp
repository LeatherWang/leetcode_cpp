
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
// 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合
void backTracking(vector<vector<int>> &res, vector<int>& tmpVec, const int& n, int start, int k)
{
    if(k<0)
        return;
    else if(k==0)
    {
        res.push_back(tmpVec);
        return;
    }

    for(int i=start; i<=n; i++)
    {
        tmpVec.push_back(i);
        backTracking(res, tmpVec, n, i+1, k-1);
        tmpVec.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>>  res;
    vector<int> tmpVec;
    backTracking(res, tmpVec, n, 1, k);
    return res;
}

int main()
{
    return 0;
}









