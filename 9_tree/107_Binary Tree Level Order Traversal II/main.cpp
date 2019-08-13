
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
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    vector<vector<int>> res;
    if(!root)
        return res;
    queue<TreeNode*> myque;
    myque.push(root);
    while(!myque.empty())
    {
        int size = myque.size();
        vector<int> tmpVec;
        for(;size>0;size--)
        {
            TreeNode *tmpNode = myque.front();
            myque.pop();
            tmpVec.push_back(tmpNode->val);

            if(tmpNode->left)
                myque.push(tmpNode->left);
            if(tmpNode->right)
                myque.push(tmpNode->right);
        }
        res.push_back(tmpVec);
    }

    for(int i=0; i< res.size()/2; i++)
        swap(res[i], res[res.size()-1-i]);
    return res;
}

int main()
{
    return 0;
}









