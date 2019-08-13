
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

void dfs(TreeNode* root, vector<int>& myvec)
{
    if(!root)
        return;
    dfs(root->left, myvec);
    myvec.push_back(root->val);
    dfs(root->right, myvec);
}
bool findTarget(TreeNode* root, int k)
{
    if(!root)
        return false;
    vector<int> myvec;
    dfs(root, myvec);

    int j=myvec.size()-1;
    int i=0;
    for(; i != j;)
    {
        int temp = myvec[i]+myvec[j];
        if(temp == k)
            return true;
        else if(temp > k)
            j--;
        else
            i++;
    }
    return false;
}

int main()
{
    return 0;
}









