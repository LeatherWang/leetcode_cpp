
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

int dfs(TreeNode * root, unordered_map<int, int> &mapSumFre)
{
    if(!root)
        return 0;

    int lSum = dfs(root->left, mapSumFre);
    int rSum = dfs(root->right, mapSumFre);

    int sum = lSum+rSum+root->val;
    auto iter = mapSumFre.find(sum);
    if(iter != mapSumFre.end())
        iter->second++;
    else
        mapSumFre[sum] = 1;

    return sum;
}

vector<int> findFrequentTreeSum(TreeNode* root)
{
    unordered_map<int, int> mapSumFre;
    dfs(root, mapSumFre);
    vector<int> res;
    int maxFre = 0;
    for(auto ele:mapSumFre)
        if(maxFre < ele.second)
            maxFre = ele.second;
    for(auto ele:mapSumFre)
        if(ele.second == maxFre)
            res.push_back(ele.first);
    return res;
}


int main()
{
    return 0;
}









