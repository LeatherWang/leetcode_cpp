
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

TreeNode* dfs(TreeNode* root, const int &val)
{
    if(!root)
        return NULL;

    if(root->val == val)
        return root;
    else if(root->val > val)
        return dfs(root->left, val);
    else
        return dfs(root->right, val);
}

TreeNode* searchBST(TreeNode* root, int val)
{
    TreeNode* res = NULL;
    return dfs(root, val);
    while(!root)
    {
        if(root->val == val)
        {
            res = root;
            break;
        }
        else if(val < root->val)
            root = root->left;
        else
            root = root->right;
    }
    return res;
}

int main()
{
    return 0;
}









