
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
class NumArray {
public:
    vector<int> vecNums;
    NumArray(vector<int> nums) {
        vecNums = nums;
    }

    int sumRange(int i, int j) {
        int res=0;
        for(int k=i; k<=j; k++)
        {
            res +=vecNums[k];
        }
        return res;
    }
};

class NumArray {
public:
    NumArray(vector<int> nums) {
        int sum = 0;
        _nums.push_back(0);
        for (unsigned i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            _nums.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return _nums[j + 1] - _nums[i];
    }

    vector<int> _nums;
};
int main()
{
    return 0;
}









