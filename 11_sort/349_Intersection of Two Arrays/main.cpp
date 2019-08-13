
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

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> res;
    if(nums1.empty() || nums2.empty())
        return res;
    unordered_set<int> setNums(nums1.begin(), nums1.end());
    unordered_set<int> setNums_2(nums2.begin(), nums2.end());

    for(unordered_set<int>::const_iterator iter = setNums.begin(); iter!=setNums.end(); iter++)
    {
        if(setNums_2.find(*iter) != setNums_2.end())
            res.push_back(*iter);
    }

    return res;
}

int main()
{
    return 0;
}









