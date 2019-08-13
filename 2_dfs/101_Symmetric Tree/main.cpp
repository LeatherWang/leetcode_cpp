
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
bool isEqual(TreeNode* p, TreeNode* q)
{
    if(!p && !q)
        return true;
    else if((!p && q) || (p && !q))
        return false;

    if(p->val == q->val)
        return isEqual(p->left, q->right) && isEqual(p->right, q->left);
    return false;
}

bool isSymmetric(TreeNode* root)
{
    if(!root) return true;
    return isEqual(root->left, root->right);
}


bool isSymmetric_NonRecursive(TreeNode* root)
{
    if(!root) return true;
    stack<TreeNode*> myStack;
    TreeNode* left = root->left, *right = root->right;

    if(left && right)
    {
        myStack.push(left);  //每次成对push
        myStack.push(right);
    }
    else if((left && !right) || (!left && right))
        return false;

    while(!myStack.empty())
    {
        right = myStack.top(); //每次成对pop
        myStack.pop();
        left = myStack.top();
        myStack.pop();
        if(left->val != right->val)
            return false;

        if(left->left && right->right)
        {
            myStack.push(left->left);
            myStack.push(right->right);
        }
        else if((left->left && !right->right) || (!left->left && right->right))
                return false;

        if(left->right && right->left)
        {
            myStack.push(left->right);
            myStack.push(right->left);
        }
        else if((left->right && !right->left) || (!left->right && right->left))
                return false;
    }
    return true;
}

int main()
{
    return 0;
}









