
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
#include <set>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int dfs(TreeNode* root, int &res, int rootValue)
{
    if(!root)
        return 0;

    int ln = dfs(root->left, res, root->val); //分解成子问题，左右子树分别最大有多少个(最长路径)跟根节点val相等
    int rn = dfs(root->right, res, root->val);

    res = max(res, ln+rn);

    if(root->val == rootValue)
        return max(ln, rn)+1;
    else
        return 0;
}

int longestUnivaluePath(TreeNode* root)
{
    int res = 0;
    dfs(root, res, 0);
    return res;
}

int main()
{
    return 0;
}









