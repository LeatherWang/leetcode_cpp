
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

int threeSumClosest(vector<int>& nums, int target)
{
    int minDisSum=INT_MAX;
    int res;
    sort(nums.begin(), nums.end());
    for(int i=0, j=0, k=0; i<nums.size(); i++)
    {
        j = i+1;
        k = nums.size() - 1;
        for(; j<k; )
        {
            int tempSum = nums[i]+nums[j]+nums[k];
            int dis = tempSum - target;
            int absDis = abs(dis);
            if(absDis < minDisSum)
            {
                //cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<endl;
                minDisSum = absDis;
                res = tempSum;
            }

            if (dis > 0)
                k--;
            else if (dis < 0)
                j++;
            else
                return target;
        }
        while(i<nums.size() && (nums[i] == nums[i+1])) {i++;}
    }
    return res;
}

// 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
// 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
int main()
{
    vector<int> myVec{0,1,2};
    cout<<"threeSumClosest: "<<threeSumClosest(myVec, 3)<<endl;
    return 0;
}









