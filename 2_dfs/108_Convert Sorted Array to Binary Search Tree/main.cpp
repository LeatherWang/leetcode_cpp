
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

void addBST(TreeNode* &root, vector<int>& nums, int start, int end)
{
    if(start > end)
        return;
    int mid = (start+end+1)/2;
    if(!root)
        root = new TreeNode(nums[mid]);
    addBST(root->left, nums, start, mid-1);
    addBST(root->right, nums, mid+1, end);
}

// leather实现
TreeNode* addBST_leather(vector<int>& nums, int start, int end)
{
    if(start > end)
        return NULL;
    int mid = (start+end+1)/2;
    TreeNode* bt = new TreeNode(nums[mid]);
    bt->left = addBST_leather(nums, start, mid-1);
    bt->right = addBST_leather(nums, mid+1, end);

    return bt;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    if(nums.empty()) return  static_cast<TreeNode*>(NULL);
    TreeNode *root = static_cast<TreeNode*>(NULL);
    addBST(root, nums, 0, nums.size()-1);
    return root;
}

void preOrderVisit(TreeNode *bst)
{
    if(bst)
    {
        cout<<bst->val<<endl;
        preOrderVisit(bst->left);
        preOrderVisit(bst->right);
    }
}

void levelOrderTraversal(TreeNode *bst)
{
    if(!bst) return;
    queue<TreeNode*> myque;
    myque.push(bst);
    for(;!myque.empty();)
    {
        int size = myque.size();
        for(;size>0;size--)
        {
            TreeNode *tempBst = myque.front();
            cout<<tempBst->val<<" ";
            myque.pop();
            if(tempBst->left)
                myque.push(tempBst->left);
            if(tempBst->right)
                myque.push(tempBst->right);
        }
        cout<<endl;
    }
}

// 二刷
TreeNode* dfs(vector<int>& nums, int start, int end)
{
    if(start >= end)
        return NULL;

    int mid = (end+start)/2;

    TreeNode *root = new TreeNode(nums[mid]);
    cout<<root->val<<endl;
    root->left = dfs(nums, start, mid);
    root->right = dfs(nums, mid+1, end);
    return root;
}

TreeNode* sortedArrayToBST_12(vector<int>& nums)
{
    if(nums.empty())
        return NULL;
    return dfs(nums, 0, nums.size());
}
int main()
{
    vector<int> myvec{-10,-3,0,5,9};
    TreeNode* root = sortedArrayToBST_12(myvec);
    levelOrderTraversal(root);

    return 0;
}









