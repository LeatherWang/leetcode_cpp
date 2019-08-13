
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
int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j)
{
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
        return 0;
    if((grid[i][j]==0) || (visited[i][j]==1))
        return 0;
    visited[i][j] = 1;
    int n1 = dfs(grid, visited, i-1, j);
    int n2 = dfs(grid, visited, i+1, j);
    int n3 = dfs(grid, visited, i, j-1);
    int n4 = dfs(grid, visited, i, j+1);
    return n1+n2+n3+n4+1;
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
    int maxArea=0;
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),0));
    for(int i=0; i<visited.size(); i++)
    {
        for(int j=0; j<visited[0].size();j++)
        {
            if((grid[i][j] != 0) && (visited[i][j]==0))
            {
                maxArea = max(dfs(grid, visited, i, j), maxArea);
            }
        }
    }
    return maxArea;
}
int main()
{
    vector<vector<int>> myvec{{0,0,1,0,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,1,1,0,0,0},
            {0,1,1,0,1,0,0,0,0,0,0,0,0},
            {0,1,0,0,1,1,0,0,1,0,1,0,0},
            {0,1,0,0,1,1,0,0,1,1,1,0,0},
            {0,0,0,0,0,0,0,0,0,0,1,0,0},
            {0,0,0,0,0,0,0,1,1,1,0,0,0},
            {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout<<maxAreaOfIsland(myvec)<<endl;
    return 0;
}









