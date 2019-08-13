
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

void backTracking(vector<string> &res, int num, int sumHour, int sumMin, int indexHour, int indexMin)
{

    if(indexHour < 0 || sumHour > 11) //!@attention 不等大于11
            return;
    if(indexMin < 0 || sumMin > 59)
            return;

    if(num == 0)
    {
        res.push_back(to_string(sumHour)+":"+ (sumMin<10?"0":"")+to_string(sumMin));
        //cout<<res.back()<<endl;
        return ;
    }

    if(indexHour > 0)
    {
        backTracking(res, num, sumHour, sumMin, indexHour-1, indexMin);
        backTracking(res, num-1, sumHour+(1<<(indexHour-1)), sumMin, indexHour-1, indexMin);
    }
    else if(indexMin > 0)
    {
        backTracking(res, num, sumHour, sumMin, indexHour, indexMin-1);
        backTracking(res, num-1, sumHour, sumMin+(1<<(indexMin-1)), indexHour, indexMin-1);
    }
}

#include "bitset"

vector<string> readBinaryWatch(int num)
{
    vector<string> res;

    for(int i=0;i<12;i++)
    {
        for(int j=0;j<60;j++)
        {
            bitset<4> hour(i);
            bitset<6> minute(j);
            if(hour.count()+minute.count()==num)
            {
                string time="";
                time+=to_string(i)+":";
                if(j<10)time+="0";
                time+=to_string(j);
                res.push_back(time);
            }
        }
    }

    return res;
}
vector<string> readBinaryWatch(int num)
{
    vector<string> res;
    backTracking(res, num, 0, 0, 4, 6);
    return res;
}

int main()
{
    readBinaryWatch(1);
    return 0;
}









