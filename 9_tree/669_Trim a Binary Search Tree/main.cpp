
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

TreeNode* dfs(TreeNode* root, int L, int R)
{
    if(!root)
        return NULL;

    if(root->val < L)
        return dfs(root->right, L, R);
    else if(root->val > R)
        return dfs(root->left, L, R);
    else
    {
        root->left = dfs(root->left, L, R);
        root->right = dfs(root->right, L, R);
        return root;
    }
}

TreeNode* trimBST(TreeNode* root, int L, int R)
{
    return dfs(root, L, R);
}

int main()
{
    return 0;
}









