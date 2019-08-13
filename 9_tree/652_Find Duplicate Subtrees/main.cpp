
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

string dfs_1(TreeNode* root, unordered_map<string, vector<TreeNode*>> &midres)
{
    if(!root)
        return '*';
    string str = "n"+to_string(root->val)+dfs_1(root->left, midres)+dfs_1(root->right, midres);
    midres[str].push_back(root);
    return str;
}

string dfs(TreeNode* root, unordered_map<string, vector<TreeNode*>> &midres)
{
    if(!root)
        return "";

    string str = "("+dfs(root->left, midres)+to_string(root->val)+dfs(root->right, midres)+")";
    midres[str].push_back(root);
    return str;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
{
    unordered_map<string, vector<TreeNode*>> midres;
    dfs(root, midres);
    vector<TreeNode*> res;
    for(auto ele:midres)
        if(ele.second.size() > 1)
            res.push_back(ele.second[0]);
    return res;
}

int main()
{
    return 0;
}









