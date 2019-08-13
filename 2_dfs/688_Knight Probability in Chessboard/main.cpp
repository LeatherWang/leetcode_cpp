
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

double dfs(vector<vector<vector<double>>> &vecTmp, const int &N, int K, int r, int c)
{
    if(r<0 || r>=N || c<0 || c>=N)
        return 0;

    if(K == 0)
        return 1;

    if(vecTmp[K][r][c] != 0)
        return vecTmp[K][r][c];
    double res = 0;
    for(int i=-2; i <= 2; i++)
    {
        if(i == 0)
            continue;
        int j = 3-abs(i);
        res += dfs(vecTmp, N, K-1, r+i, c+j) + dfs(vecTmp, N, K-1, r+i, c-j);
    }
    return vecTmp[K][r][c] = res;
}

double knightProbability(int N, int K, int r, int c)
{
    vector<vector<vector<double>>> vecTmp(K+1, vector<vector<double>>(N, vector<double>(N, 0))); //! @attention 使用了double类型
    double ans = dfs(vecTmp, N, K, r, c);
    double b= pow(8, K);
    cout<<ans<<" " <<b<<endl;
    return (double)((double)ans/b);
}
int main()
{
    //cout<<knightProbability(8, 30, 6, 4)<<endl;
    cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long long);
        cout << "\t最大值：" << (numeric_limits<unsigned long long>::max)();
        cout << "\t最小值：" << (numeric_limits<unsigned long long>::min)() << endl;
        cout << "double: \t" << "所占字节数：" << sizeof(double);
        cout << "\t最大值：" << (numeric_limits<double>::max)();
        cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;

    return 0;
}









