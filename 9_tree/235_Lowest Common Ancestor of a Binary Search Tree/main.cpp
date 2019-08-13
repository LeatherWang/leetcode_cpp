
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(!root || !p || !q)
        return NULL;
    vector<TreeNode*> vecNodeP, vecNodeQ;
    TreeNode *tmpNode = root;
    TreeNode *res = NULL;
    bool findP = false, findQ = false;
    for(;tmpNode;)
    {
        vecNodeP.push_back(tmpNode);
        if(tmpNode->val > p->val)
            tmpNode = tmpNode->left;
        else if(tmpNode->val < p->val)
            tmpNode = tmpNode->right;
        else
        {
            findP = true;
            break;
        }
    }
    tmpNode = root;
    for(;tmpNode;)
    {
        vecNodeQ.push_back(tmpNode);
        if(tmpNode->val > q->val)
            tmpNode = tmpNode->left;
        else if(tmpNode->val < q->val)
            tmpNode = tmpNode->right;
        else
        {
            findQ = true;
            break;
        }
    }
    if(findP && findQ)
    {
        int size = min(vecNodeP.size(), vecNodeQ.size());
        for(int i=0; i<size; i++)
        {
            if(vecNodeP[i] == vecNodeQ[i])
                res = vecNodeP[i];
            else
                break;
        }
    }
    return res;
}

int main()
{
    return 0;
}









