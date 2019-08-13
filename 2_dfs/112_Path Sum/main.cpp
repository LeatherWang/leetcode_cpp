
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

bool dfs(TreeNode* bt, int curSum, int &tarSum)
{
    if(bt)
    {
        if(!bt->left && !bt->right)  //判断叶子节点
        {
            if((curSum+bt->val)==tarSum)
                return true;
            return false;
        }
        if(dfs(bt->left, bt->val+curSum, tarSum))
            return true;
        if(dfs(bt->right, bt->val+curSum, tarSum))
            return true;
    }
    else
    {
        //! @attention 这里不能判定为叶子节点啊
    }
    return false;
}
bool hasPathSum(TreeNode* root, int sum)
{
    if(!root) return false;
    return dfs(root, 0, sum);
}

//! 排名第一的代码，完全按照dfs的结构，另外使用了`sum - root->val`
bool hasPathSum(TreeNode* root, int sum)
{
    if (root == NULL)
        return false;
    if (root->left == NULL&&root->right == NULL)
        return sum == root->val;
    if (root->left != NULL)
        if (hasPathSum(root->left, sum - root->val))
            return true;
    if (root->right != NULL)
        if (hasPathSum(root->right, sum - root->val))
            return true;
    return false;
}

int main()
{
    return 0;
}









