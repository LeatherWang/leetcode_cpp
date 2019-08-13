
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

int levelOrderTraversal(TreeNode* bt)
{
    if(!bt) return 0;
    queue<TreeNode*> myque;
    myque.push(bt);
    int depth = 1;
    for(;!myque.empty();)
    {
        int size = myque.size();
        while(size-- > 0)
        {
            TreeNode* tempNode = myque.front();
            myque.pop();
            if(!tempNode->left && !tempNode->right)
                return depth;
            if(tempNode->left)
                myque.push(tempNode->left);
            if(tempNode->right)
                myque.push(tempNode->right);
        }
        depth++;
    }
    return depth;
}

int minDepth(TreeNode* root)
{
    return levelOrderTraversal(root);
}
int main()
{
    TreeNode *mybt = new TreeNode(3);
    return 0;
}









