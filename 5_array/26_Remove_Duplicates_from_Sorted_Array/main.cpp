
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

int removeDuplicates(vector<int>& nums)
{
    if(!nums.size())
        return 0;
    int length=1;
//    int dupNum = INT_MAX;
//    int lastNum = INT_MAX;
    for(int i=1; i<nums.size(); i++)
    {
        /*if(nums[i] == dupNum)
            continue;
        else
        {
            if(nums[i] != lastNum)
            {
                nums[length] = nums[i];
                length++;
            }
            else
                dupNum = nums[i];
        }
        lastNum = nums[i];*/
        if(nums[i] != nums[i-1])
        {
            nums[length] = nums[i];
            length++;
        }
    }
    return length;
}

// [0,0,1,1,1,2,2,3,3,4]
int main()
{
    vector<int> myvec{};
    int n = removeDuplicates(myvec);
    for(int i=0; i<n; i++)
        cout<<myvec[i]<<" ";
    cout<<endl;
    return 0;
}









