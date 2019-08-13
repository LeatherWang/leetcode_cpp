
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

int secondNum, minNum;
bool dfs(TreeNode* root)
{
    if(!root)
        return false;
    if(root->val < minNum)
    {
        secondNum = minNum;
        minNum = root->val;
    }
    else if(root->val > minNum)
    {
        if(secondNum == -1 || root->val < secondNum)
            secondNum = root->val;
    }

    if(dfs(root->left))
        dfs(root->right);
    return true;
}

int findSecondMinimumValue(TreeNode* root)
{
    if(!root)
        return -1;
    minNum = root->val;
    secondNum = minNum;
    dfs(root);
    return secondNum!=-1?secondNum:-1;
}

int main()
{
    return 0;
}









