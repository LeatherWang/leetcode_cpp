
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
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
// 输入: [ [1,2], [2,3], [3,4], [1,3] ]
// 输出: 1
int eraseOverlapIntervals(vector<Interval>& intervals)
{
    if(!intervals.size())
        return 0;
    sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){return a.end < b.end;});

    int num=1;
    int endPos = intervals[0].end;
    for(int i=1; i<intervals.size(); i++)
    {
        if(endPos <= intervals[i].start)
        {
            num++;
            endPos = intervals[i].end;
        }
    }
    return intervals.size() - num;
}

int main()
{
    return 0;
}









