
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
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int dfs(TreeNode* root, const int &k, int &cur, int &res)
{
    if(!root)
        return 0;

    if(k == dfs(root->left, k, cur, res))
        return k;
    if(++cur == k)
    {
        res = root->val;
        return k;
    }
    if(k == dfs(root->right, k, cur, res))
        return k;

    return 0;
}

int kthSmallest(TreeNode* root, int k)
{
    int cur = 0, res = 0;
    dfs(root, k, cur, res);
    return res;

    stack<TreeNode *> mystack;
    TreeNode * T = root;
    int counter = 0;
    while(!mystack.empty() || T)
    {
        while(T)
        {
            mystack.push(T);
            T = T->left;
        }

        if(!mystack.empty())
        {
            T = mystack.top();
            mystack.pop();
            counter++;
            if(counter == k)
                return T->val;
            T = T->right;
        }
    }
    return 0;
}

int main()
{
    return 0;
}









