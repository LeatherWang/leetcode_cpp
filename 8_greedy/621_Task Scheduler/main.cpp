
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

using namespace std;
// 输入: tasks = ["A","A","A","B","B","B"], n = 2
// 输出: 8
int leastInterval(vector<char>& tasks, int n)
{
    vector<int> tasksNum_1(26,0), tasksNum;
    for(auto t:tasks)
        tasksNum_1[t-'A']++;
    for(auto a:tasksNum_1)
        if(a!=0)
            tasksNum.push_back(a);
    sort(tasksNum.begin(), tasksNum.end(), [](const int &a, const int &b){return a>b;});

    int res=0;
    for(;;)
    {
        for(int i=0; i<=n; i++)
        {
            if(i<tasksNum.size())
            {
                if(tasksNum[0] == 0 && tasksNum[i]==0)
                    return res;
                if(tasksNum[i] > 0)
                    --tasksNum[i];
            }
            else
            {
                if(tasksNum[0] == 0)
                    return res;
            }
            res++;
        }
        sort(tasksNum.begin(), tasksNum.end(), [](const int &a, const int &b){return a>b;});
        if(tasksNum[0] == 0)
            return res;
    }
}

// 排名第一的算法
int leastInterval(vector<char>& tasks, int n)
{
    vector<int> dp(26,0);
    int ret=0;
    for(auto a: tasks){
        dp[a-'A']++;
    }
    sort(dp.begin(),dp.end(),[](int c,int d){return c>d;});
    int i =0, mx = dp[0], len = tasks.size();
    while (i < 26 && dp[i] == mx) i++;
    return max(len, (mx - 1) * (n + 1) +  i);
}

int main()
{
    string str= "AAABBBCCC";
    vector<char> tasks(str.begin(), str.end());
    cout<<leastInterval(tasks, 3)<<endl;
    return 0;
}









