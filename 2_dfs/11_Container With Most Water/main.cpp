
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

int maxArea(vector<int>& height)
{
    int res=0;
    for(int i=0; i< height.size(); i++)
    {
        for(int j=i+1; j< height.size(); j++)
        {
            res = max(res, min(height[i], height[j])*(j-i));
        }
    }
    return res;
}

// 排名第一的算算法，O(N)
int maxArea(vector<int>& height)
{
    int res = 0;
    int left = 0, right = height.size()-1;
    while(left<right)
    {
        if(height[left] < height[right])
        {
            res = max(res, height[left]*(right-left));
            left++;
        }
        else
        {
            res = max(res, height[right]*(right-left));
            right--;
        }
    }
    return res;
}

int main()
{
    return 0;
}









