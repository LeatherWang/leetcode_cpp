
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

TreeNode* dp(vector<int>& pre, vector<int>& post, int ps, int pe, int qs, int qe)
{
    if(ps > pe || qs > qe)
        return NULL;

    TreeNode* root = new TreeNode(pre[ps]);
    cout<<ps<<" "<<pe<<" "<<qs<<" "<<qe<< endl;

    if(ps == pe) //! @attention 不可缺少，因为下面使用的是`pre[ps+1] != post[pos]`
        return root;

    int pos = qs;
    while(pre[ps+1] != post[pos])
        pos++;
    root->left = dp(pre, post, ps+1, ps+pos-qs+1, qs, pos);
    root->right = dp(pre, post, ps+pos-qs+2, pe, pos+1, qe-1);
    return root;
}

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post)
{
    return dp(pre, post, 0, pre.size()-1, 0, post.size()-1);
}

// pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
int main()
{
    vector<int> pre = {1,2,4,5,3,6,7};
    vector<int> post = {4,5,2,6,7,3,1};
    constructFromPrePost(pre, post);
    return 0;
}









