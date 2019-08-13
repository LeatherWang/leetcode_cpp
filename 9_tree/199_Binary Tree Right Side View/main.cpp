
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


vector<int> rightSideView(TreeNode* root)
{
    vector<int> res;
    if(!root)
        return res;
    queue<TreeNode*> myque;
    myque.push(root);
    while(!myque.empty())
    {
        res.push_back(myque.back()->val);
        int size = myque.size();
        for(int i=0; i<size; i++)
        {
            TreeNode * tmpNode = myque.front();
            myque.pop();
            if(tmpNode->left)
                myque.push(tmpNode->left);
            if(tmpNode->right)
                myque.push(tmpNode->right);
        }
    }
    return res;
}

int main()
{
    return 0;
}









