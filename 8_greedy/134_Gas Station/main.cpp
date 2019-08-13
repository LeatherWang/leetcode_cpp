
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
// gas  = [1,2,3,4,5]
// cost = [3,4,5,1,2]
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    for(int i=0; i<gas.size(); i++)
    {
        int gasNum=0;
        int j=i;
        for(;;)
        {
            gasNum +=gas[j];
            gasNum -=cost[j];
            if(gasNum < 0)
                break;
            j++;
            if(j == gas.size())
                j=0;
            if(j == i)
                return i;
        }
    }
    return -1;
}

int main()
{
    return 0;
}









