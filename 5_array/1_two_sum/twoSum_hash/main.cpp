
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <math.h>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> vTwoNum;
    unordered_map<int, int> mapNumIndex;
    for(int i=0; i<nums.size(); i++)
    {
        mapNumIndex.insert(make_pair(nums[i], i));
    }
    for(int i=0; i<nums.size();i++)
    {
        int a1 = target-nums[i];
        auto iter = mapNumIndex.find(a1);
        if(iter != mapNumIndex.end() && iter->second != i) //注意第二个判定条件，很机制
        {
            vTwoNum.push_back(iter->second); //注意这个push_back的顺序啊，一定是这样，小的index在前面，大的index在后面
            vTwoNum.push_back(i);
            break;
        }
    }
    return vTwoNum;
}

vector<int> twoSum2(vector<int>& nums, int target) {
    vector<int> vTwoNum;
    unordered_map<int, int> mapNumIndex;
    for(int i=0; i<nums.size();i++)
    {
        int a1 = target-nums[i];
        auto iter = mapNumIndex.find(a1);
        if(iter != mapNumIndex.end())
        {
            vTwoNum.push_back(i);
            vTwoNum.push_back(iter->second);
            break;
        }
        mapNumIndex.insert(make_pair(nums[i], i));
    }
    return vTwoNum;
}


int main()
{
    int myints[] = {3,3,5,2}; //{2, 7, 11, 15};
    int target = 7;//9;
    vector<int> myVector(myints, myints+4);
    vector<int> vecTar = twoSum1(myVector, target);

    for(auto item : vecTar)
        cout<<item<<" ";
    cout<<endl;

    vecTar = twoSum2(myVector, target);

    for(auto item : vecTar)
        cout<<item<<" ";
    cout<<endl;
    return 0;
}
