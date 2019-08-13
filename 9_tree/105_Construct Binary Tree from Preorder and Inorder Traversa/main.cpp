
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

TreeNode* dp(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie)
{
    if(ps>pe || is>ie)
        return NULL;
    int pos=is;
    while(preorder[ps] != inorder[pos])
        pos++;
    TreeNode * root = new TreeNode(preorder[ps]);
    root->left = dp(preorder, inorder, ps+1, ps+pos-is, is, pos-1);
    root->right = dp(preorder, inorder, ps+pos-is+1, pe, pos+1, ie);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    return dp(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
}


int main()
{
    return 0;
}









