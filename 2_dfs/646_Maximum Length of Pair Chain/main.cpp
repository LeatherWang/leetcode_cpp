
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

int findLongestChain(vector<vector<int>>& pairs)
{
    if(pairs.empty())
        return 0;
    auto cmp = [](const vector<int> &a, const vector<int> &b){return a[1] < b[1];};
    sort(pairs.begin(), pairs.end(), cmp);

    int res = 1;
    int endT = pairs[0][1];
    for(vector<int> ele:pairs)
    {
        if(ele[0]  > endT)
        {
            res++;
            endT = ele[1];
        }
    }
    return res;
}

int main()
{
    return 0;
}









