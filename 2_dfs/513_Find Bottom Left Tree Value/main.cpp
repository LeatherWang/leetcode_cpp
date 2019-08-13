
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

int findBottomLeftValue(TreeNode* root)
{
    queue<TreeNode*> myque;
    TreeNode* mytar;
    myque.push(root);
    while(!myque.empty())
    {
        int size = myque.size();
        mytar = myque.front();
        for(;size > 0; --size)
        {
            TreeNode* tempNode = myque.front();
            myque.pop();
            if(tempNode->left)
                myque.push(tempNode->left);
            if(tempNode->right)
                myque.push(tempNode->right);
        }
    }
    return mytar->val;
}
int main()
{
  //  binaryTreePaths();
    return 0;
}









