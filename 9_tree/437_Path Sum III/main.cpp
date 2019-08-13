
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

int dfs(TreeNode *root, map<int ,int>& mapList, const int &sum, int curSum)
{
    if(!root)
        return 0;
    curSum +=root->val;

    int counter = 0;
    map<int ,int>::iterator iter = mapList.find(curSum-sum);
    if(iter != mapList.end())
        counter = iter->second;

    map<int ,int>::iterator iter2 = mapList.find(curSum);
    if(iter2 != mapList.end())
        iter2->second++;
    else
        mapList[curSum] = 1;

    int a = dfs(root->left, mapList, sum, curSum);
    int b = dfs(root->right, mapList, sum, curSum);
    mapList[curSum]--;
    return counter+a+b;
}
int pathSum(TreeNode* root, int sum)
{
    map<int ,int> mapList;
    mapList[0] = 1;
    return dfs(root, mapList, sum, 0);
}

int main()
{
    return 0;
}









