
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

vector<vector<int>> threeSum_myself(vector<int>& nums)
{
    vector<vector<int>> resVec;
    set<vector<int>> mySetVec;
    unordered_set<string> mySetStr;
    unordered_map<int,int> myNumMap;
    vector<int> myNumUnique;
    for(int number:nums)
    {
        if(myNumMap.find(number) != myNumMap.end())
            myNumMap[number]++; //计数
        else
        {
            myNumUnique.push_back(number);
            myNumMap[number] = 1;
        }
    }

    for(int firstNum:myNumUnique)
    {
        if(firstNum > 0)
            continue;
        int twoSum = 0-firstNum; // <=0
        for(int secondNum:myNumUnique)
        {
            if(secondNum < 0) // >=0
                continue;
            int thirdNum = twoSum - secondNum;
            if(myNumMap.find(thirdNum) != myNumMap.end())
            {
                if(firstNum == secondNum) //0,0,0
                    if(myNumMap[0] < 3)
                        continue;
                if(firstNum == thirdNum)
                {
                    if(myNumMap[firstNum] < 2)
                        continue;
                }
                if(secondNum == thirdNum)
                {
                    if(myNumMap[secondNum] < 2)
                        continue;
                }

                vector<int> tempVec{firstNum, secondNum, thirdNum};
                sort(tempVec.begin(), tempVec.end());

                //!@attention 下面的操作太费时了，换成了set<vector<int>>或者set<string>
/*                bool insertFlag = true;
                for(vector<int> vec:resVec)
                {
                    if(vec[0] == tempVec[0] && vec[1] == tempVec[1]) //只需要比较前两个
                    {
                        insertFlag = false;
                        break;
                    }
                }
                if(insertFlag)
                {
                    resVec.push_back(tempVec);
                    cout<<firstNum<<" "<<secondNum<<" "<<thirdNum<<endl;
                }*/
                ostringstream myostr;
                myostr<<tempVec[0]<<tempVec[1]<<tempVec[2];
                if(mySetStr.find(myostr.str()) == mySetStr.end())
                {
                    mySetStr.insert(myostr.str());
                    resVec.push_back(tempVec);
                }
                //mySetVec.insert(tempVec);
            }
        }
    }
//    for(vector<int> vec:mySetVec)
//    {
//        resVec.push_back(vec);
//    }
    return resVec;
}

vector<vector<int>> threeSum(vector<int>& nums)
{
    int i = 0, j, k;
    vector<vector<int> > result;
    if (nums.size() < 3)
        return result;
    sort(nums.begin(), nums.end()); //排序
    while(i < nums.size() - 2 && nums[i] <= 0)
    {
        j = i + 1;
        k = nums.size() - 1;
        while (j < k)
        {
            if (nums[j] + nums[k] == -nums[i])
            {
                vector<int> vecTemp = {nums[i], nums[j], nums[k]};
                result.push_back(vecTemp);
                while(nums[j] == nums[++j]){}
                while(nums[k] == nums[--k]){}
            }
            else if (nums[j] + nums[k] > -nums[i])
                k--;
            else
                j++;
        }
        while(nums[i] == nums[++i]) {} //去重复
    }
    return result;
}

class base
{
    public:
    base()=default;
    ~base()=default;
    private:
    static int a;
    int b;
    char c;

};

int main()
{
    cout<<"A's size is "<<sizeof(base)<<endl;

    vector<int> myvec{-1, 0, 1, 2, -1, -4};
    threeSum(myvec);
    return 0;
}









