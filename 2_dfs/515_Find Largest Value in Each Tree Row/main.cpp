
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

vector<int> largestValues(TreeNode* root)
{
    queue<TreeNode*> myque;
    vector<int> resVec;
    if(!root)
        return resVec;
    myque.push(root);
    while(!myque.empty())
    {
        int size = myque.size();
        vector<int> tempVec(size);
        for(;size > 0; --size)
        {
            TreeNode* tempNode = myque.front();
            tempVec[size-1] = tempNode->val;
            myque.pop();
            if(tempNode->left)
                myque.push(tempNode->left);
            if(tempNode->right)
                myque.push(tempNode->right);
        }
        sort(tempVec.begin(), tempVec.end(), [](int a, int b){return a>b;});
        resVec.push_back(tempVec[0]);
    }
    return resVec;
}
int main()
{
  //  binaryTreePaths();
    return 0;
}









