
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
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    stack<TreeNode*> mystack;
    BSTIterator(TreeNode *root) {
        while(root)
        {
            mystack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(mystack.empty())
            return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* T = mystack.top();
        mystack.pop();
        int res = T->val;
        T = T->right;
        while(T)
        {
            mystack.push(T);
            T = T->left;
        }
        return res;
    }
};

int main()
{
    return 0;
}









