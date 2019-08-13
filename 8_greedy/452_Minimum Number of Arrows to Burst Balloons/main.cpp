
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

// [[3,9],[7,12],[3,8],[6,8],[9,10],[2,9],[0,9],[3,9],[0,6],[2,8]]
int findMinArrowShots(vector<pair<int, int>>& points)
{
    if(points.empty())
        return 0;
    sort(points.begin(), points.end(), [](const pair<int,int>&a, const pair<int,int>&b){return a.second<b.second;});

    int res=1;
    int endPos=points[0].second;
    for(int i=1; i<points.size();i++)
    {
        if(points[i].first <= endPos && endPos <=points[i].second)
        {
        }
        else
        {
            res++;
            endPos = points[i].second;
        }
    }
    return res;
}

int main()
{
    return 0;
}









