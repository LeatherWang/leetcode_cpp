
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
TreeNode* clone(TreeNode* root){
    if(root == nullptr)
        return nullptr;
    TreeNode* newroot = new TreeNode(root->val);
    newroot->left = clone(root->left);
    newroot->right = clone(root->right);
    return newroot;
}
vector<TreeNode *> generateTrees(int n) {
    if(n == 0)
        return vector<TreeNode *>();

    vector<TreeNode *> res(1,nullptr);
    for(int i = 1; i <= n; i++){
        vector<TreeNode *> tmp;

        for(int j = 0; j<res.size();j++){
            TreeNode* oldroot = res[j];
            TreeNode* root = new TreeNode(i);
            TreeNode* target = clone(oldroot);
            root->left = target;
            tmp.push_back(root);

            if(oldroot!=nullptr){
                TreeNode* tmpold = oldroot;
                while(tmpold->right!=nullptr){ //取right是因为这是二叉搜索树
                    TreeNode* nonroot = new TreeNode(i);
                    TreeNode *tright = tmpold->right;

                    tmpold->right = nonroot;
                    nonroot->left = tright; //nonroot是最大的节点，所以老数的其余部分要放到坐端

                    TreeNode *target = clone(oldroot); //使用clone是为了不改变原来树的结构啊
                    tmp.push_back(target);

                    tmpold->right = tright; //复原
                    tmpold = tmpold->right;
                }
                tmpold->right = new TreeNode(i);
                TreeNode *target = clone(oldroot);
                tmp.push_back(target);
                tmpold->right = nullptr;
            }
        }
        res=tmp;
    }
    return res;
}
int main()
{
    TreeNode *mybt = new TreeNode(3);
    return 0;
}









