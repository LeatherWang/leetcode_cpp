
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

vector<TreeNode*> allPossibleFBT(int N)
{
    vector<TreeNode *> res;
    if(N == 0)
        return res;
    if(N == 1)
    {
        TreeNode *root = new TreeNode(0);
        res.push_back(root);
        return res;
    }

    for(int i=1; i< N; i++)
    {
        vector<TreeNode*> left = allPossibleFBT(i);
        vector<TreeNode*> right = allPossibleFBT(N-i-1);

        for(TreeNode* li:left)
            for(TreeNode* ri:right)
            {
                TreeNode * root = new TreeNode(0);
                root->left = li;
                root->right = ri;
                res.push_back(root);
            }
    }

    return res;
}

// 排名第一的算法
map<int, vector<TreeNode*>> cache;
vector<TreeNode*> allPossibleFBT(int N) {
    vector<TreeNode*> res;
    if(cache.count(N) > 0) return cache[N];

    if(N < 1 || N % 2 == 0) return res;
    if(N == 1){
        TreeNode* root = new TreeNode(0);
        res.push_back(root);
    }

    if(N > 1){
        for(int i = 1; i <= N; i++){
            vector<TreeNode*> left = allPossibleFBT(i-1);
            vector<TreeNode*> right = allPossibleFBT(N-i);

            int lsize = left.size();
            int rsize = right.size();

            for(int i = 0; i < lsize; i++){
                for(int j = 0; j < rsize; j++){
                    TreeNode* root = new TreeNode(0);
                    root->left = left[i];
                    root->right = right[j];
                    res.push_back(root);
                }
            }
        }
    }

    cache[N] = res;
    return res;
}

int main()
{
    return 0;
}









