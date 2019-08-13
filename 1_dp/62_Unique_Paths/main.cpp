
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
int **paths;
int searchPath(int m, int n)
{
    if(m<0 || n<0)
        return 0;
    if((m+n) == 0)
        return 1;

    if(paths[m][n] != -1)
        return paths[m][n];

    return (paths[m][n] = (searchPath(m-1, n)+searchPath(m, n-1)));
}

// m是列数，n是行数
int uniquePaths_myself(int m, int n)
{
    paths = new int *[m];
    for(int i=0; i<m; i++)
    {
        paths[i] = new int [n];
        memset(paths[i], -1, n*sizeof(int));
    }
    return searchPath(m-1,n-1);
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m,vector<int> (n));
    for(int i=0;i<m;i++){
        dp[i][0]=1;
    }
    for(int j=0;j<n;j++){
        dp[0][j]=1;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    cout<<uniquePaths(7,3)<<endl;
    return 0;
}









