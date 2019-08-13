
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

string dfs(TreeNode *root)
{
    if(!root)
        return string();
    string tmpStr;
    tmpStr = to_string(root->val);

    if(!root->left && !root->right)
        return tmpStr;

    tmpStr +="("+dfs(root->left)+")";
    string temp = dfs(root->right);
    if(temp.size())
        tmpStr +="("+temp+")";
    return tmpStr;
}
string tree2str(TreeNode* t)
{

}

int main()
{
    return 0;
}









