
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

using namespace std;
string optimalDivision(vector<int>& nums)
{
    string res;
    res +=to_string(nums[0]);
    if(nums.size() == 1)
        return res;
    if(nums.size() == 2)
        return res+"/"+to_string(nums[1]);
    res +="/(";
//    for(int i=1; i<nums.size(); i++)
//        res +=to_string(nums[i])+"/";
//    res.back() = ')';
    for(int i=1; i<nums.size()-1; i++)
        res +=to_string(nums[i])+"/";
    res.back() = to_string(nums.back()) +")"; //特殊的特殊处理

    return res;
}

int main()
{
    return 0;
}









