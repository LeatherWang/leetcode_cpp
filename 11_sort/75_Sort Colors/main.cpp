
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

void sortColors(vector<int>& nums)
{
    // 冒泡排序
    /*bool flag;
    int size = nums.size();
    for(;size > 0; size--)
    {
        flag = false;
        for(int i=1; i< size; i++)
        {
            if(nums[i-1] > nums[i])
            {
                swap(nums[i-1], nums[i]);
                flag = true;
            }
        }
        if(!flag)
            return;
    }*/

    // 插入排序
    /*int size = nums.size();
    for(int i=1; i< size; i++)
    {
        for(int j=i; j>0; j--)
            if(nums[j] < nums[j-1])
                swap(nums[j], nums[j-1]);
    }*/

    //排名第一的算法
    int size = nums.size();
    if(size < 2)
        return;
    int l=0, r=size-1, index=0;
    for(;index <= r;)
    {
        if(nums[index] == 2)
        {
            nums[index] = nums[r];
            nums[r--] = 2;
        }
        else if(nums[index] == 0)
        {
            nums[index] = nums[l];
            nums[l++] = 0;
            index++;
        }
        else
        {
            index++;
        }
    }
}

int main()
{
    return 0;
}









