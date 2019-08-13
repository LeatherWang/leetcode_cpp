
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
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode *root, int curSum, int &res)
{
    if(!root) return;

    if(!root->left && !root->right)
    {
        res += curSum*10+root->val;
        return;
    }
    dfs(root->left, curSum*10+root->val, res);
    dfs(root->right, curSum*10+root->val, res);
    return;
}
int sumNumbers(TreeNode* root)
{
    int res = 0;
    dfs(root, 0, res);
    return res;
}

TreeNode* Insert(TreeNode* BST, int X )
{
    if( !BST )
    {
        BST = new TreeNode(X);
    }
    else
    {
        if( X < BST->val )
            BST->left = Insert(BST->left, X);
        else if( X > BST->val )
            BST->right = Insert(BST->right, X);
    }
    return BST;
}

void PreOrderTraversal( TreeNode* BT )
{
    if(BT)
    {
        cout<<BT->val<<" "<<ends;
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->right);
    }
}

int main()
{
    int myarr[]={2,1,3};
    int k;
    k=sizeof(myarr)/sizeof(myarr[0]);
    cout<<"建立排序二叉树顺序: "<<endl;
    TreeNode* myBT1=NULL;
    for(int i=0; i<k; i++)
    {
        myBT1 = Insert(myBT1, myarr[i]);
    }
    PreOrderTraversal(myBT1);
    cout<<endl<<endl;
    cout<<sumNumbers(myBT1)<<endl;
    return 0;
}









