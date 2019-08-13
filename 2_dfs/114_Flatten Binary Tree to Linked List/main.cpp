
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

void dfs(TreeNode *root, TreeNode * &pre)
{
    if(!root) return;
    if(!pre)
        pre = root;
    else
    {
        pre->right = root;
        pre->left = NULL; //!@attention 左侧要置空
        pre = pre->right;
    }
    cout<<pre->val<<endl;
    TreeNode* curRight = root->right;
    dfs(root->left, pre);
    dfs(curRight, pre);
}

void flatten(TreeNode* root)
{
    TreeNode *pre=NULL; //!@attention 别忘了赋值NULL
    dfs(root, pre);
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
    int myarr[]={4,1,2,3,5,6};
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
    flatten(myBT1);
    PreOrderTraversal(myBT1);
    cout<<endl;
    return 0;
}









