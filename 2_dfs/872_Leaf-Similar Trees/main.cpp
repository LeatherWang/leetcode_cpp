
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

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* bt, vector<int>& myvec)
{
    if(bt)
    {
        if(!(bt->left) && (!bt->right))
        {
            myvec.push_back(bt->val);
            return;
        }

        dfs(bt->left, myvec);
        dfs(bt->right, myvec);
    }
}
bool leafSimilar(TreeNode* root1, TreeNode* root2)
{
    vector<int> vecLeaf1;
    vector<int> vecLeaf2;
    dfs(root1, vecLeaf1);
    dfs(root2, vecLeaf2);

    if(vecLeaf1.size() != vecLeaf2.size())
        return false;
    for(int i=0; i<vecLeaf1.size(); i++)
        if(vecLeaf1[i] != vecLeaf2[i])
            return false;
    return true;
}
int main()
{
    return 0;
}









