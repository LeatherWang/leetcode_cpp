
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
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* bt, int curSum, vector<vector<int>>& res, vector<int>& seed)
{
    if(!bt)
        return;

    if(!bt->left && !bt->right)
    {
        if(curSum == bt->val)
        {
            seed.push_back(bt->val);
            res.push_back(seed);
            seed.pop_back();
            return;
        }
        else
            return;
    }

    seed.push_back(bt->val);
    dfs(bt->left, curSum-bt->val, res, seed);
    dfs(bt->right, curSum-bt->val, res, seed);
    seed.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum)
{
    vector<vector<int>> res;
    vector<int> seed;
    dfs(root, sum, res, seed);
    return res;
}

int main()
{
    return 0;
}









