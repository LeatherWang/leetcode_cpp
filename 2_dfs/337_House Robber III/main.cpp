
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
#include <sstream>
#include <set>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 我自己实现的，时间在1s以上, 究其原因，应该是重复计算
int dfs_leather(TreeNode* root, bool lastRobed)
{
    if(!root) return 0;

    if(lastRobed)
        return dfs_leather(root->left, false)+dfs_leather(root->right, false);
    else
    {
        int n1 = dfs_leather(root->left, false)+dfs_leather(root->right, false);
        int n2 = dfs_leather(root->left, true)+dfs_leather(root->right, true)+root->val;
        return max(n1, n2);
    }
}
int dfs(TreeNode* root, int &l, int &r)
{
    if(!root) return 0;
    int ll=lr=rl=rr=0;
    l = dfs(root->left, ll, lr); //使用引用的方式记录第三行的执行结果，返回给上一次的调用者
    r = dfs(root->right, rl, rr);
    return max(root->val+ll+lr+rl+rr, l+r); //ll,lr,rl,rr是第三层的结果，加上root->val就是结果
}
int rob(TreeNode* root)
{
    //return dfs_leather(root, false);
    int l, r;
    return dfs(root, l, r);
}

int main()
{
    return 0;
}









