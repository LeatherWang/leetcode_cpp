
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

bool res = true;
int dfs(TreeNode* bt)
{
    if(!bt) return 0;
    int l = dfs(bt->left);
    int r = dfs(bt->right);
    if(abs(l-r) > 1)
        res = false;
    return max(l, r)+1;
}
bool isBalanced(TreeNode* root)
{
    dfs(root);
    return res;
}

int main()
{
    return 0;
}









