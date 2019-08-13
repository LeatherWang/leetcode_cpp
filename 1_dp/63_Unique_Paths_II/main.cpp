
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


int uniquePathsWithObstacles_myself(vector<vector<int>>& obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> resVec(n, vector<int>(m, 0));
    bool flagRight = false;
    for(int i=0; i<m; i++)
    {
        if(obstacleGrid[0][i])
            flagRight = true;
        resVec[0][i] = flagRight?0:1;
    }
    bool flagDown = false;
    for(int i=0; i<n; i++)
    {
        if(obstacleGrid[i][0])
            flagDown = true;
        resVec[i][0] = flagDown?0:1;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(!obstacleGrid[i][j])
            {
                resVec[i][j] = (obstacleGrid[i-1][j]?0:resVec[i-1][j])+ //!@attention 这里的判断是没必要的，因为障碍物所在的resVec肯定是0
                        (obstacleGrid[i][j-1]?0:resVec[i][j-1]);
            }
        }
    }
    return resVec[n-1][m-1];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    if(m==0) return 0;
    int n = obstacleGrid[0].size();
    if(n==0) return 0;

    int f[m][n];
    f[0][0] = obstacleGrid[0][0]==1?0:1;

    // 第一行
    for(int j=1;j<n;j++) {
        f[0][j] = obstacleGrid[0][j]==1?0:f[0][j-1]; //! 精炼
    }
    // 第一列
    for(int i=1;i<m;i++) {
        f[i][0] = obstacleGrid[i][0]==1?0:f[i-1][0];
    }

    for(int i=1;i<m;i++) {
        for(int j=1;j<n;j++) {
            f[i][j] = obstacleGrid[i][j]==1?0:f[i-1][j] + f[i][j-1];
        }
    }

    return f[m-1][n-1];
}
int main()
{
    vector<vector<int>> myvec(3,vector<int>(3,0));
    myvec[1][1] = 1;
    cout<<uniquePathsWithObstacles(myvec)<<endl;

//! do some test
//    int **myarr = new int*[10];
//    for(int i=0; i<10; i++)
//        myarr[i] = new int[10];
    int myarr[10][6];
    memset(myarr, -1, sizeof(myarr));
    cout<<sizeof(myarr)<<" "<<myarr[5][5]<<endl;
    return 0;
}









