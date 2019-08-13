
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

TreeNode* dfs(vector<int>& nums, int IndexStart, int IndexEnd)
{
    if(IndexStart >= IndexEnd)
        return NULL;
    pair<int, int> pairMaxNum=make_pair(IndexStart, nums[IndexStart]);
    for(int i=IndexStart; i<IndexEnd;i++)
    {
        if(nums[i] > pairMaxNum.second)
            cout<<nums[i]<<endl;
    }

    TreeNode *root = new TreeNode(pairMaxNum.second);
    cout<<root->val<<" "<<pairMaxNum.second<<endl;

    root->left = dfs(nums, IndexStart, pairMaxNum.first);
    root->right = dfs(nums, pairMaxNum.first+1, IndexEnd);
    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums)
{
    if(nums.empty())
        return NULL;
    return dfs(nums, 0, nums.size());
}

int main()
{
    vector<int> myvec{3,2,1,6,0,5};
    pair<int, int> pairMaxNum = make_pair(1,1);
    pairMaxNum = make_pair(2,2);
    cout<<pairMaxNum.second<<endl;
    constructMaximumBinaryTree(myvec);
    return 0;
}









