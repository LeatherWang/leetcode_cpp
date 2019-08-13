
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

//int dfs(vector<int>& nums, int num, vector<int>& midRes)
//{
//    if(num < 0)
//        return 0;
//    else if(num==0)
//        return 1;

//    if(midRes[num] != -1)
//        return midRes[num];
//    int res = 0;
//    for(int i=0; i<nums.size(); i++)
//    {
//        res += dfs(nums, num-nums[i], midRes);
//    }
//    return midRes[num] = res;
//}

//int combinationSum4(vector<int>& nums, int target)
//{
//    vector<int> midRes(target+1, -1);
//    return dfs(nums, target, midRes);
//}



struct TreeNode {
TreeNode *left;
TreeNode *right;
};
int TreeDepth(TreeNode *root) {
    if(!root)
        return 0;
    queue<TreeNode *> myque;
    myque.push(root);
    int res = 0;
    while(!myque.empty())
    {
        int size = myque.size();
        for(int i=0; i< size; i++)
        {
            TreeNode * tmpNode = myque.front();
            myque.pop();
            if(tmpNode->left)
                myque.push(tmpNode->left);
            if(tmpNode->right)
                myque.push(tmpNode->right);
        }
        res++;
    }
    return res;
}
//Top-K Frequent Words
//Given a word sequence, return a list of K words that occur most frequently in this
//word sequence.
std::vector<std::string> FindTopK(const std::vector<std::string> &words, const int K)
{
    if(words.empty() || K==0)
        return vector<string>();

    map<string, int> mapTmp;
    vector<pair<string ,int>> vecTmp;
    for(auto word:words)
    {
        auto iter = mapTmp.find(word);
        if(iter == mapTmp.end())
        {
            mapTmp[word] = vecTmp.size();
            vecTmp.push_back(make_pair(word, 1));
        }
        else
        {
            vecTmp[iter->second].second++;
        }
    }

    auto cmp = [](const pair<string ,int> &a, const pair<string ,int> & b)
    {
        return a.second>b.second;
    };
    sort(vecTmp.begin(), vecTmp.end(), cmp);

    vector<std::string> res(K, "");

    for(int i=0; i< K; i++)
        res[i] = vecTmp[i].first;
    return res;
}
int main()
{
    return 0;
}







