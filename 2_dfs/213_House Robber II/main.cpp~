
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

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traversal(TreeNode* bt, vector<string> &myVecStr, string str)
{
    if(bt)
    {
        if(!(bt->left) && (!bt->right))
        {
            myVecStr.push_back(str+std::to_string(bt->val));
            return;
        }

        traversal(bt->left, myVecStr, str+std::to_string(bt->val)+"->");
        traversal(bt->right, myVecStr, str+std::to_string(bt->val)+"->");
    }
}

vector<string> binaryTreePaths(TreeNode* root)
{
    vector<string> myVecStr;
    if(!root)
        return myVecStr;
    traversal(root, myVecStr, "");
    for(string str:myVecStr)
        cout<<str<<endl;
    return myVecStr;
}
int main()
{
  //  binaryTreePaths();
    return 0;
}









