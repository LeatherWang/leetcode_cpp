
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
vector<int> resVec;
int f(int n)
{
    if(n < 0) return 0;
    if(n < 2) return 1; //0 or 1

    return resVec[n]=((resVec[n-1]!=-1?resVec[n-1]:f(n-1))+
                      (resVec[n-2]!=-1?resVec[n-2]:f(n-2)));
}

// 用递归实现
int climbStairs(int n)
{
    //!@attention 递归，考虑重复计算
    resVec = vector<int>(n+1, -1);
    return f(n);
}

// 用递推实现
int climbStairs_recurrence(int n)
{
    vector<int> mystatus(n+1,0);
    mystatus[1] = 1;
    mystatus[2] = 2;

    //递推公式: mystatus[i]=mystatus[i-1]+mystatus[i-2]
    for(int i=3; i<=n; i++)
        mystatus[i]=mystatus[i-1]+mystatus[i-2];
    return mystatus[n];
}

int main()
{
    cout<<climbStairs(44)<<endl;
    cout<<climbStairs_recurrence(44)<<endl;
    return 0;
}









