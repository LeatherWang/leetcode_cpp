
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
int serarchLeft(const vector<int>& nums, int L, int R, const int& target)
{
    if(L>R || nums[R] < target)
        return R+1;
    for(;L<=R;)
    {
        int mid = L+(R-L)/2;
        if(nums[mid] == target)
        {
            return serarchLeft(nums, L, mid-1, target);
        }
        else if(nums[mid] > target)
            R = mid-1;
        else
            L = mid+1;
    }
    return -1;
}

int serarchRight(const vector<int>& nums, int L, int R, const int& target)
{
    if(L>R || nums[L] > target)
        return L-1;

    for(;L<=R;)
    {
        int mid = L+(R-L)/2;
        if(nums[mid] == target)
        {
            return serarchRight(nums, mid+1, R, target);
        }
        else if(nums[mid] > target)
            R = mid-1;
        else
            L = mid+1;
    }
    return -1;
}

vector<int> searchRange_myself(vector<int>& nums, int target)
{
    if(nums.empty()) return vector<int>{-1,-1};
    int L=0, R=nums.size()-1;
    for(;L<=R;)
    {
        int mid = L+(R-L)/2;
        if(nums[mid] == target)
        {
            return vector<int>{serarchLeft(nums, L, mid-1, target),
                        serarchRight(nums, mid+1, R, target)};
        }
        else if(nums[mid] > target)
            R = mid-1;
        else
            L = mid+1;
    }
    return vector<int>{-1,-1};
}





vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> res;
    int left = 0;
    int right = nums.size() - 1;
    while ( left <= right ) {
        int mid = (left+right)/2;
        if ( nums[mid] < target ) {
            left = mid+1;
        }
        else {
            right = mid-1;
        }
        if ( nums[left] == target ) { // 左侧本来就是比target小的，如果left=mid+1导致条件成立，那么左边界就确定了
                                      // 这步比较不是必须的，只是为了加速
            res.push_back(left);
            break;
        }
    }
    right = nums.size() - 1;
    while ( left <= right ) {
        int mid = (left+right)/2;
        if ( nums[mid] > target ) {
            right = mid-1;
        }
        else {
            left = mid+1;
        }
        if ( nums[right] == target ) {
            res.push_back(right);
            break;
        }
    }
    if (res.size()!=2){
        res.clear();
        res.push_back(-1),res.push_back(-1);
        return res;
    } else {
        return res;
    }
}
// 输入: nums = [5,7,7,8,8,8,8,8,8,8,8,10], target = 8
// 输出: [3,4]
int main()
{
    vector<int> myvec{5,7,7,8,8,8,8,8,8,8,8,10};
    auto res = searchRange(myvec, 6);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}









