
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归表达式:max(nums[beg] - partition(beg + 1, end), nums[end] - partition(beg, end + 1))

int dfs(vector<int>& nums, vector<vector<int>>& midStatus, int begin, int end)
{
    if(begin > end)
        return 0;

    if(midStatus[begin][end] != -1)
        return midStatus[begin][end];
    else
        return midStatus[begin][end] = max(nums[begin]-dfs(nums, midStatus, begin+1, end), nums[end]-dfs(nums, midStatus, begin, end-1));
}

bool PredictTheWinner(vector<int>& nums)
{
    vector<vector<int>> midStatus(nums.size(), vector<int>(nums.size(), -1));
    if(dfs(nums, midStatus, 0, nums.size()-1) >= 0)
        return true;
    return false;
}

int main()
{
    return 0;
}









