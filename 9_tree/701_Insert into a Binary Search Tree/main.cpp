
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

void dfs(TreeNode* root, const int &val)
{
    if(!root)
        return ;
    if(val < root->val)
    {
        if(!root->left)
            root->left = new TreeNode(val);
        else
            dfs(root->left, val);
    }
    else
    {
        if(!root->right)
            root->right = new TreeNode(val);
        else
            dfs(root->right, val);
    }
}

TreeNode* insertIntoBST(TreeNode* root, int val)
{
    dfs(root, val);
    return root;
}

int main()
{
    return 0;
}









