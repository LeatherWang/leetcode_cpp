
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

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> res;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    for(int i=0, j=0; i< nums1.size() && j<nums2.size();)
    {
        if(nums1[i] == nums2[j])
        {
            res.push_back(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i] < nums2[j])
            i++;
        else j++;
    }
    return res;
}

int main()
{
    return 0;
}









