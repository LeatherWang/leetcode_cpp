
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

int dfs(TreeNode *root, bool leftF)
{
    if(!root)
        return 0;
    int res=0;
    if(!root->left && !root->right)
    {
        if(leftF)
            return root->val;
        else
            return 0;
    }
    res += dfs(root->left, true);
    res += dfs(root->right, false);
    return res;
}
int sumOfLeftLeaves(TreeNode* root)
{
    return dfs(root, false);
}
int main()
{
    return 0;
}









