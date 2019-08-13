
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
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode *root, vector<int> &res)
{
    if(!root)
        return;

    dfs(root->left, res);
    res.push_back(root->val);
    dfs(root->right, res);
}
vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> res;
    dfs(root, res);
    return res;
}

int main()
{
    return 0;
}









