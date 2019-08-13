
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
int search(vector<int>& nums, int target)
{
    if(nums.empty()) return -1;
    int L=0, R=0;
    if(nums[0] == target)
        return 0;
    else if(nums[0] > target)
    {
        L = 0;
        R = nums.size()-1;
        if(nums[R] < target)
            return -1;
        while(L<=R)
        {
            int mid = L+(R-L)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
            {
                if(nums[mid] > nums[R])
                    L = mid+1;
                else R = mid-1; //mid进入右侧小序列
            }
            else //mid进入右侧小序列
            {
                L = mid+1;
            }
        }
    }
    else
    {
        L = 0;
        R = nums.size()-1;
        while(L<=R)
        {
            int mid = L+(R-L)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target) //mid进入左侧大序列
            {
                R = mid - 1;
            }
            else
            {
                if(nums[mid] >= nums[L]) //mid进入左侧大序列，注意这里是>=，是为了避免输入为"[1,3] 3"这种情况
                    L = mid + 1;
                else
                    R = mid - 1;
            }
        }
    }

    return -1;
}

int search(vector<int>& nums, int target)
{
    int left=0,right=nums.size()-1;
    while(left<=right)
    {
        int m=(left+right)/2;
        if(target==nums[m]) return m;
        if(nums[m]>=nums[left]){
            if(nums[left]<=target&&nums[m]>=target) //nums[m]>=target中的等于号不会出现，见上一步啊
            {
                right=m-1;
            }else{
                left=m+1;
            }
        }
        else{
            if(nums[right]>=target&&nums[m]<=target)
            {
                left=m+1;
            }else{
                right=m==0?m:m-1;
            }
        }
    }
    return -1;
}

int search(vector<int>& nums, int target)
{
    int n = nums.size();
    int lo = 0, hi = n-1;
    while(lo<hi)
    {
        int mid = (lo+hi)/2;
        if(nums[mid] > nums[hi])
            lo = mid+1;
        else
            hi = mid; //! @attention 注意不是mid-1
    }

    int rot = lo;
    lo = 0, hi = n-1;

    while(lo <= hi)
    {
        int mid = (lo+ hi)/2;
        //mid is just a virtual index, take the array below as an example
        //[6,7,1,2,3,4,5] => [6,7,1,2,3,4,5,[6,7]]
        //to access 6 in the array, 7 % 7 = 0
        //to access 7 in the array, 8 % 7 = 1
        int realMid = (rot+mid)%n; //! @attention 注意跟mid索引处的nums[mide]无关，mid只是一个virtual index
        if(nums[realMid] == target)
            return realMid;
        else if(nums[realMid] < target)
            lo = mid+1;
        else
            hi = mid-1;

    }
    return -1;
}

int main()
{
    vector<int> myvec{2,3,1};
    cout<<search(myvec, 3)<<endl;
    return 0;
}









