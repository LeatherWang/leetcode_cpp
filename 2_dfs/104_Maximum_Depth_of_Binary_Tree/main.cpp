
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

int postOrderTraversal(TreeNode* bt)
{
    if(bt)
    {
        int hl = postOrderTraversal(bt->left);
        int hr = postOrderTraversal(bt->right);
        return max(hl, hr)+1;
    }
    return 0;
}
int maxDepth(TreeNode* root)
{
    return postOrderTraversal(root);
}

int main()
{
    TreeNode *mybt = new TreeNode(3);
    return 0;
}









