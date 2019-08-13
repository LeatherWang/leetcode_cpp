
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

TreeNode* dfs(TreeNode* root)
{
    if(!root)
        return NULL;

    root->left = dfs(root->left);
    root->right = dfs(root->right);

    if(!root->left && !root->right && root->val==0)
        return NULL;
    else return root;
}

TreeNode* pruneTree(TreeNode* root)
{
    root = dfs(root);
    return root;
}

int main()
{
    return 0;
}









