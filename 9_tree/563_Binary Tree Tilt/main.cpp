
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

int dfs(TreeNode *root, int& val)
{
    if(!root)
        return 0;
    int valL=0, valR=0;
    int valTiltL = dfs(root->left, valL);
    int valTiltR = dfs(root->right, valR);
    val = root->val + valL + valR;
    return abs(valL-valR) + valTiltL + valTiltR;
}
int findTilt(TreeNode* root)
{
    return dfs(root, 0);
}

int main()
{
    return 0;
}









