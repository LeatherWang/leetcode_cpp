
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

vector<double> averageOfLevels(TreeNode* root)
{
    vector<double> res;
    queue<TreeNode *> myque;
    myque.push(root);
    while(!myque.empty())
    {
        int size = myque.size();
        double sum = 0.0;
        for(int i=0; i< size; i++)
        {
            TreeNode * tmpNode = myque.front();
            myque.pop();
            sum += tmpNode->val;
            if(tmpNode->left)
                myque.push(tmpNode->left);
            if(tmpNode->right)
                myque.push(tmpNode->right);
        }
        res.push_back(sum/size);
    }
    return res;
}

int main()
{
    return 0;
}









