
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

// 这个版本总是超时，why??
TreeNode* inOrderTraversal(TreeNode* bt, TreeNode* pre) //pre表示新右斜二叉树最后一个节点
{
    if(!bt) return pre;
    TreeNode *curPre = inOrderTraversal(bt->left, pre); //直到遇到第一个最左节点才能返回
    curPre->right = bt; // 修改right指针
    curPre->left = NULL; //将left置空
    return inOrderTraversal(bt->right, curPre->right); //开始遍历右侧，`curPre->right`是新右斜二叉树最后一个节点，重复上述过程
}
TreeNode* increasingBST(TreeNode* root)
{
    TreeNode *dummyBT = new TreeNode(0); //哑节点
    TreeNode *pre = dummyBT;
    inOrderTraversal(root, pre);
    return dummyBT->right;
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
        cout<<BT->val<<endl;
        PreOrderTraversal(BT->left);
        PreOrderTraversal(BT->right);
    }
}

// 容易理解的版本
TreeNode* increasingBST(TreeNode* root) {
    if(root==NULL)
        return NULL;
    TreeNode* resH=NULL;
    TreeNode* tail=NULL;
    search(root,resH,tail);
    return resH;
}

void search(TreeNode* root,TreeNode* &resH,TreeNode* &tail)// `TreeNode* &resH`免去使用哑节点
{
    if(root==NULL)return;

    search(root->left,resH,tail);

    TreeNode* p=new TreeNode(root->val);
    if(resH==NULL)
    {
        resH=p; //保存头节点
        tail=p;
    }
    else
    {
        tail->right=p;
        tail=p;
    }

    search(root->right,resH,tail);
}
int main()
{
    int myarr[]={379,826};
    int k;
    k=sizeof(myarr)/sizeof(myarr[0]);
    cout<<"建立排序二叉树顺序: "<<endl;
    TreeNode* myBT1=NULL;
    for(int i=0; i<k; i++)
    {
        myBT1 = Insert(myBT1, myarr[i]);
    }

    PreOrderTraversal(increasingBST(myBT1));
    return 0;
}









