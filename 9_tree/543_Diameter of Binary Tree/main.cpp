
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

int dfs(TreeNode* root, int &maxD)
{
    if(!root)
        return 0;

    int maxL=0, maxR=0;
    int a = dfs(root->left, maxL);
    int b = dfs(root->right, maxR);
    maxD = max(maxL, maxR)+1;
    return max(maxL+maxR, max(a, b));
}

int diameterOfBinaryTree(TreeNode* root)
{
    int maxD = 0;
    return dfs(root, maxD);
}


int main()
{
    return 0;
}









