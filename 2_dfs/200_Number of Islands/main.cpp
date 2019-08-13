
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
void dfs(vector<vector<char>>& grid, int row, int col)
{
    if(grid[row][col] == '0')
        return;

    grid[row][col] = '0';
    if(row-1 >= 0) dfs(grid, row-1, col);
    if(row+1 < grid.size()) dfs(grid, row+1, col);
    if(col-1 >= 0) dfs(grid, row, col-1);
    if(col+1 < grid[0].size()) dfs(grid, row, col+1);
}

int numIslands(vector<vector<char>>& grid)
{
    int res = 0;
    for(int i=0; i<grid.size(); i++)
        for(int j=0; j<grid[0].size(); j++)
            if(grid[i][j] == '1')
            {
                dfs(grid, i, j);
                res++;
            }
    return res;
}


// 二刷
void dfs(vector<vector<char>>& grid, int i, int j, const int &rows, const int &cols)
{
    if(grid[i][j] == 0)
        return;

    grid[i][j] = 0;
    if(i>0)
        dfs(grid, i-1, j, rows, cols);
    if(i+1<rows)
        dfs(grid, i+1, j, rows, cols);
    if(j>0)
        dfs(grid, i, j-1, rows, cols);
    if(j+1<cols)
        dfs(grid, i, j+1, rows, cols);
}

int numIslands(vector<vector<char>>& grid)
{
    int res = 0;
    if(grid.empty())
        return res;
    int rows = grid.size();
    int cols = grid[0].size();
    for(int i=0; i< rows; i++)
    {
        for(int j=0; j< cols; j++)
        {
            if(grid[i][j] != 0)
            {
                dfs(grid, i, j, rows, cols);
                res++;
            }
        }
    }
    return res;
}
int main()
{
    return 0;
}









