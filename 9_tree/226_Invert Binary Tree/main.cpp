
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

void dfs(TreeNode* root)
{
    if(!root)
        return;
    if(!root->left && !root->right)
        return;
    TreeNode *left = root->left;
    root->left = root->right;
    root->right = left;

    dfs(root->left);
    dfs(root->right);
}
TreeNode* invertTree(TreeNode* root)
{
    dfs(root);
    return root;
}

int main()
{
    return 0;
}









