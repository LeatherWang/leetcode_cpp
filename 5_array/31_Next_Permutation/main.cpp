
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
void nextPermutation(vector<int>& nums)
{
    if(nums.empty())
        return;
    int minDis = INT_MAX;
    for(int i = nums.size()-2; i>=0; i--)
    {
        int minNumIndex;
        for(int j=i+1; j<nums.size(); j++)
        {
            if(nums[i] < nums[j])
            {
                int dis = nums[j] - nums[i];
                if( dis < minDis)
                {
                    minDis = dis;
                    minNumIndex = j;
                }
            }
        }
        if(minDis != INT_MAX)
        {
            swap(nums[i], nums[minNumIndex]); //交换位置
            sort(nums.begin()+i+1, nums.end()); //后面的要从小到大重新排列啊，比如输入1,3,2时，输出应该是213，而不是231
            return;
        }
    }

    sort(nums.begin(), nums.end());
    return;
}

//1,2,3 → 1,3,2
//3,2,1 → 1,2,3
//1,1,5 → 1,5,1
// 1 2 3 4  1 2 4 5 6 5 4 3
int main()
{
    vector<int> myvec{1,3,2};
    nextPermutation(myvec);
    for(int i:myvec)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}









