
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
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* root)
{
    stack<TreeNode*> mystack;
    vector<int> res;
    while(!mystack.empty() || root)
    {
        while(root)
        {
            res.push_back(root->val);
            mystack.push(root);
            root = root->left;
        }

        if(!mystack.empty())
        {
            root = mystack.top();
            mystack.pop();
            root = root->right;
        }
    }
    return res;
}



// 改成中序遍历
void dfs(TreeNode* root, TreeNode* &pre)
    {
        if(!root)
            return;
        
        dfs(root->left, pre);
        if(!pre)
            pre = root;
        else
        {
            root->left = NULL;
            pre->right = root;
            pre = root;
        }
        dfs(root->right, pre);
    }
TreeNode* flatten_2(TreeNode* root) {
        TreeNode* pre = NULL;
        dfs(root, pre);
        return pre;
    }

int main()
{
    return 0;
}









