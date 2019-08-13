#include <iostream>
#include <cstring>
#include <list>
using namespace std;
int main()
{
    string str1, str2;
    while(cin>>str1>>str2)
    {
        int m = str1.size();
        int n = str2.size();
        int **dp = new int* [m+1];
        for(int i=0; i<= m; i++)
            dp[i] = new int [n+1];

        for(int i=0; i<= m; i++)
            dp[i][0] = 0;
        for(int i=1; i<= n; i++)
            dp[0][i] = 0;
        for(int i=1; i<= m; i++)
        {
            for(int j=1; j<= n; j++)
            {
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        cout<<dp[m][n]<<endl;
    }
    return 0;
}
