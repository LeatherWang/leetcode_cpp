
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
#include <deque>

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
    deque<TreeNode*> mydeq;
    mydeq.push_back(root);
    bool goingRight = true;
    while(!mydeq.empty())
    {
        int size = mydeq.size();
        vector<int> vecTmp;
        for(int i=0; i<size; i++)
        {
            if(goingRight)
            {
                TreeNode *tmp = mydeq.front();
                mydeq.pop_front();

                vecTmp.push_back(tmp->val);

                if(tmp->left)
                    mydeq.push_back(tmp->left);
                if(tmp->right)
                    mydeq.push_back(tmp->right);
            }
            else
            {
                TreeNode *tmp = mydeq.back();
                mydeq.pop_back();

                vecTmp.push_back(tmp->val);

                if(tmp->right)
                    mydeq.push_front(tmp->right);
                if(tmp->left)
                    mydeq.push_front(tmp->left);
            }
        }
        goingRight = !goingRight;
        res.push_back(vecTmp);
    }
    return res;
}

vector<vector<int>> levelOrder_2(TreeNode* root)
{
    if(!root)
        return vector<vector<int>>();
    vector<vector<int>> res;
    queue<TreeNode*> myque;
    myque.push(root);
    bool goingR= true;
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
        if(goingR)
            res.push_back(vecTmp);
        else
            res.push_back(vector<int>(vecTmp.rbegin(),vecTmp.rend()));
        goingR = !goingR;
    }
    return res;
}


int main()
{
    return 0;
}









