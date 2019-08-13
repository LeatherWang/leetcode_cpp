
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include "time.h"
#include "memory.h"

using namespace std;

int dfs(int * dataArr, int index, int sum, const int &N)
{
    if(sum < 0)
        return 0;
    else if(sum == 0)
        return 1;

    if(index >= N)
        return 0;

    return dfs(dataArr, index+1, sum, N) + dfs(dataArr, index+1, sum-dataArr[index], N);
}

int main()
{
    int N;
    cin>>N;
    int *dataArr = new int[N+1]; //故意增加一维，为了遍历方便

    int **resArr = new int *[40+1];
    for(int i=0; i <= 40; i++)
    {
        resArr[i] = new int[N+1];
        memset(resArr[i], 0, (N+1)*sizeof(int)); //初始化为0
    }

    resArr[0][0] = 1;
    for(int i=1; i <= N; i++)
    {
        cin>>dataArr[i];
        resArr[0][i] = 1;
    }

    for(int i=1; i <= 40; i++)
    {
        for(int j=1; j <= N; j++)
        {
            resArr[i][j] = resArr[i][j-1];
            if(i-dataArr[j] >= 0)
            {
                resArr[i][j] += resArr[i-dataArr[j]][j-1];
            }
        }
    }
    cout<<resArr[40][N]<<endl;

    //cout<<dfs(dataArr, 0, 40, N)<<endl;

    delete [] dataArr;
    for(int i=0; i<40+1; i++)
        delete [] resArr[i];
    delete [] resArr;
    return 0;
}









