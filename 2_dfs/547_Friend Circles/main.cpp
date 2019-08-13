
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
void dfs(vector<vector<int>>& M, vector<int> &visited, int index)
{
    if(visited[index])
        return;
    visited[index] = 1;
    for(int i=0; i<M.size(); i++)
    {
        if(M[index][i])
        {
            dfs(M, visited, i);
        }
    }
}
int findCircleNum(vector<vector<int>>& M)
{
    vector<int> visited(M.size(), 0);
    int res=0;
    for(int i=0; i<visited.size(); i++)
    {
        if(!visited[i])
        {
            dfs(M, visited, i);
            res++;
        }
    }
    return res;
    switch (control) {
    case value:

        break;
    default:
        break;
    }
}







void dfs_1(vector<vector<int>>& M, vector<int> &visited, int index)
{
    if(visited[index] == 1)
        return ;

    visited[index] = 1;
    for(int j=0; j<M.size(); j++)
    {
        if(M[index][j])
            dfs(M, visited, j);
    }
}

int findCircleNum(vector<vector<int>>& M)
{
    int res = 0;
    vector<int> visited(M.size(), 0);
    for(int i=0; i<M.size(); i++)
    {
        if(visited[i] == 0)
        {
            dfs_1(M, visited, i);
            res++;
        }
    }
    return res;
}







int main()
{
    return 0;
}









