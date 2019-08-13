
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
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root)
{
    if(!root)
        return vector<vector<int>>();
    vector<vector<int>> res;
    queue<TreeNode*> myque;
    myque.push(root);
    while(!myque.empty())
    {
        int size = myque.size();
        vector<int> vecTmp;
        for(int i=0; i<size; i++)
        {
            TreeNode *tmp = myque.front();
            myque.pop();
            vecTmp.push_back(tmp->val);
            if(tmp->left)
                myque.push(tmp->left);
            if(tmp->right)
                myque.push(tmp->right);
        }
        res.push_back(vecTmp);
    }
    return res;
}

int main()
{
    return 0;
}









