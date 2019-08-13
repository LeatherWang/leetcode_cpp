
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
TreeNode* iterBuild(vector<int>& inorder, int is, int ie,
                    vector<int>& postorder, int ps, int pe, unordered_map<int ,int> &mapList)
{
    if(is > ie || ps>pe)
        return NULL;
    int ri = mapList[postorder[pe]];
    TreeNode * root = new TreeNode(postorder[pe]);
    root->left = iterBuild(inorder, is, ri-1, postorder, ps, ps+ri-is-1, mapList);
    root->right = iterBuild(inorder, ri+1, ie, postorder, ps+ri-is, pe-1, mapList);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    if(inorder.size()!=postorder.size() || !inorder.size() || !postorder.size())
        return NULL;
    unordered_map<int ,int> mapList;
    for(int i=0; i<inorder.size(); i++)
        mapList.insert(make_pair(inorder[i], i));

    return iterBuild(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mapList);
}

// 中序遍历 inorder = [9,3,15,20,7]
// 后序遍历 postorder = [9,15,7,20,3]
int main()
{
    TreeNode *mybt = new TreeNode(3);
    return 0;
}









