
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

using namespace std;

int removeElement(vector<int>& nums, int val)
{
    vector<int>::size_type oriIndex=0, endIndex=nums.size();
    for(; oriIndex < endIndex; )
    {
        if(nums[oriIndex] == val)
        {
            nums[oriIndex] = nums[endIndex-1];
            endIndex--;
            continue;
        }
        oriIndex++;
    }
    return oriIndex;
}

// 给定 nums = [0,1,2,2,3,0,4,2], val = 2,
// 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
int main()
{
    vector<int> myvec{0,1,2,2,3,0,4,2};
    int n = removeElement(myvec, 2);
    for(int i=0; i<n; i++)
        cout<<myvec[i]<<" ";
    cout<<endl;
    return 0;
}









