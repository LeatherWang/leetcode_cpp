
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

void dfs(TreeNode* &t1, TreeNode* &t2)
{
    if(!t1 && !t2)
        return;
    if(!t1)
    {
        t1 = t2;
        return;
    }
    else if(!t2)
    {
        return;
    }
    t1->val += t2->val;
    dfs(t1->left, t2->left);
    dfs(t1->right, t2->right);
}
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{
    dfs(t1, t2);
    return t1;
}

int main()
{
    return 0;
}









