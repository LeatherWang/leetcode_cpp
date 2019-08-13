
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

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void dfs(TreeNode* root, unordered_map<int, int> & midRes)
{
    if(!root)
        return ;
    auto iter = midRes.find(root->val);
    if(iter != midRes.end())
        iter->second++;
    else
        midRes[root->val] = 1;

    dfs(root->left, midRes);
    dfs(root->right, midRes);
}

vector<int> findMode(TreeNode* root)
{
    if(!root)
        return vector<int>();

    unordered_map<int, int> midRes;
    dfs(root, midRes);

    vector<int> res;
    int fre = 0;
    auto iter = midRes.begin();
    for(; iter != midRes.end(); iter++)
    {
        if(iter->second == fre)
            res.push_back(iter->first);
        else if(iter->second > fre)
        {
            fre = iter->second;
            res.clear();
            res.push_back(iter->first);
        }
    }
    return res;
}


int main()
{
    return 0;
}









