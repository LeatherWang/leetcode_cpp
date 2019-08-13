
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
int searchInsert(vector<int>& nums, int target)
{
    int L=0, R=nums.size()-1;
    for(;L<=R;)
    {
        int mid = L+(R-L)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            R = mid-1;
        else
            L = mid+1;
    }
    return L;
}
// 输入: [1,3,5,6], 5
// 输出: 2
// 输入: [1,3,5,6], 2
// 输出: 1
int main()
{
    vector<int> myvec{1,3,5,6,8};
    cout<<searchInsert(myvec, 2)<<endl;
    return 0;
}









