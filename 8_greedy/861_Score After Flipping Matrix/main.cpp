
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
#include <set>

using namespace std;

int matrixScore(vector<vector<int>>& A)
{
    for(int i=0; i<A.size(); i++)
    {
        if(A[i][0] == 0)
        {
            for(int j=0; j<A[0].size(); j++)
                A[i][j] = A[i][j]==0?1:0;
        }
    }

    for(int j=1; j<A[0].size(); j++)
    {
        int sum=0;
        for(int i=0; i<A.size(); i++)
            if(A[i][j])
                ++sum;
        if(sum<(A.size()+1)/2)
        {
            for(int i=0; i<A.size(); i++)
                A[i][j] = A[i][j]==0?1:0;;
        }
    }

    int res=0;
    for(int i=0; i<A.size(); i++)
    {
        int tmp=0;
        for(int j=0; j<A[0].size(); j++)
            tmp = (tmp<<1) + A[i][j];
        res += tmp;
    }
    return res;
}

int main()
{
    vector<int> commands = {4,-1,4,-2,4};
    vector<vector<int>> obstacles = {{2,4}};
    robotSim(commands, obstacles);
    return 0;
}









