
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

bool dfs_2(TreeNode* s, TreeNode* t)
{
    if(!s && !t)
        return true;
    if((!s && t) || (s && !t))
        return false;

    if(s->val != t->val)
        return false;

    if(dfs_2(s->left, t->left) && dfs_2(s->right, t->right))
        return true;

    return false;
}

bool dfs(TreeNode* s, TreeNode* t)
{
    if(!s)
        return false;
    if(s->val == t->val)
    {
        if(dfs_2(s, t))
            return true;
    }

    if(dfs(s->left, t) || dfs(s->right, t))
        return true;
    return false;
}
bool isSubtree(TreeNode* s, TreeNode* t)
{
    return dfs(s, t);
}

int main()
{
    return 0;
}









