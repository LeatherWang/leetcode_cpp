
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
int minPathSum(vector<vector<int>>& grid)
{
    if(grid.empty()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    int myStatus[m][n];
    memset(myStatus, 0, sizeof(myStatus));
    myStatus[0][0] = grid[0][0];
    for(int i=1; i < m; i++)
        myStatus[i][0] = myStatus[i-1][0] + grid[i][0];
    for(int i=1; i < n; i++)
        myStatus[0][i] = myStatus[0][i-1] + grid[0][i];

    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            myStatus[i][j] = min(myStatus[i-1][j], myStatus[i][j-1]) + grid[i][j];
        }
    }
    return myStatus[m-1][n-1];
}








// 二刷
int minPathSum(vector<vector<int>>& grid)
{
    if(grid.empty())
        return 0;
    int m = grid.size();
    int n = grid[0].size();

    for(int i=1; i < n; i++)
        grid[0][i] += grid[0][i-1];
    for(int i=1; i < m; i++)
        grid[i][0] += grid[i-1][0];

    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
        }
    }
    return grid[m-1][n-1];
}





int main()
{
    vector<vector<int>> myGrid;
    myGrid.push_back(vector<int>{1,3,1});
    myGrid.push_back(vector<int>{1,5,1});
    myGrid.push_back(vector<int>{4,2,1});
    cout<<minPathSum(myGrid)<<endl;
    return 0;
}









