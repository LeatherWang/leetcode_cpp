
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

int rob(vector<int>& nums)
{
    int n = nums.size();
    if(!n)
        return 0;
    vector<int> midRes(n, 0);

    midRes[0] = nums[0];
    if(n == 1)
        return midRes[0];
    midRes[1] = max(nums[0], nums[1]);
    if(n == 2)
        return midRes[1];

    for(int i=2; i<(n-1); i++)
    {
        midRes[i] = max(midRes[i-1], midRes[i-2]+nums[i]);
    }

    int res1 = midRes[n-2];
    if(n > 2)
    {
        midRes[1] = nums[1];
        midRes[2] = max(nums[2], midRes[1]);
        for(int i=3; i<n; i++)
        {
            midRes[i] = max(midRes[i-1], midRes[i-2]+nums[i]);
        }
    }

    return max(res1, midRes.back());
}

int main()
{
  //  binaryTreePaths();
    return 0;
}









