
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
int dfs(vector<int> &num, vector<int> &vecSum, int index)
{
    if(index >= num.size())
        return 0;
    if(vecSum[index] != -1)
        return vecSum[index];

    int a1 = dfs(num, vecSum, index+1);
    int a2 = num[index] + dfs(num, vecSum, index+2);

    return vecSum[index]=max(a1, a2);
}

int rob(vector<int>& nums)
{
    //vector<int> vecSum(nums.size(), -1);
    //cout<<"dfs: "<<dfs(nums, vecSum, 0)<<endl;

    if(nums.empty())
        return 0;
    for(int i=1; i< nums.size(); i++)
    {
        nums[i] = max(nums[i]+(i>1?nums[i-2]:0), nums[i-1]);
    }
    return nums.back();
}

int main()
{
    //  binaryTreePaths();
    return 0;
}









