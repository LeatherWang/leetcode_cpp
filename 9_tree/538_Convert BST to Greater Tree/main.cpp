
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

int dfs(TreeNode *root, int val)
{
   if(!root)
       return val;
   root->val +=dfs(root->right, val);
   return dfs(root->left, root->val);
}
TreeNode* convertBST(TreeNode* root)
{

}


int main()
{
    return 0;
}









