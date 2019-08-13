
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <math.h>
#include <list>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> vecTar, vecCandidator;
    map<int,int> mapNumIndex;
    for(int i=0; i<nums.size(); i++)
    {
        int number = nums[i];
        vecCandidator.push_back(number);

        pair<map<int, int>::iterator, bool> insert_pair;
        insert_pair = mapNumIndex.insert(pair<int,int>(number, i));
        if(!insert_pair.second)
        {
            if(2*number == target)
            {
                auto iter2 = mapNumIndex.find(number);
                vecTar.push_back(iter2->second);
                vecTar.push_back(i);
                return vecTar;
            }
        }

    }

    sort(vecCandidator.begin(), vecCandidator.end());

    int N = vecCandidator.size();
    int less_index=0, big_index=N-1;
    while(1)
    {
        int sum=vecCandidator[less_index]+vecCandidator[big_index];
        cout<<sum<<endl;
        if(sum == target)
        {
            auto iter1 = mapNumIndex.find(vecCandidator[less_index]);
            vecTar.push_back(iter1->second);
            auto iter2 = mapNumIndex.find(vecCandidator[big_index]);
            vecTar.push_back(iter2->second);
            sort(vecTar.begin(), vecTar.end());
            break;
        }
        else if(sum > target)
        {
            big_index--;
        }
        else
        {
            less_index++;
        }

        if(big_index == less_index)
            break;
    }
    return vecTar;
}

int main()
{
    int myints[] = {3,3,5,2}; //{2, 7, 11, 15};
    int target = 6;//9;
    vector<int> myVector(myints, myints+4);
    vector<int> vecTar = twoSum(myVector, target);

    for(auto item : vecTar)
        cout<<item<<" ";
    cout<<endl;
    return 0;
}
