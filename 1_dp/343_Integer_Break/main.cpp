
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
#include <ctime>

using namespace std;
vector<int> mystatus;
int iterFind(int n, bool firstIter)
{
    if(n == 1 || n==0)
        return 1;
    if(mystatus[n-1] != -1)
        return mystatus[n-1];
    vector<int> vecMul(n,0);
    for(int i=1; i<= n; i++)
    {
        if(firstIter && i==n)
            continue;
        vecMul[i-1] = i*iterFind(n-i, false);
    }
    sort(vecMul.begin(),vecMul.end());
    return mystatus[n-1] = vecMul[n-1];
}

int integerBreak_myself(int n)
{
    if(n==0) return 0;
    mystatus = vector<int>(n,-1);
    bool firstIter = true;  //保证最少两个数
    return iterFind(n, firstIter);
}

//O(N)时间
int integerBreak(int n)
{
    if(n==2) return 1;
    if(n==3) return 2;
    int product = 1;
    while(n>4){
        product*=3;
        n-=3;
    }
    product*=n;

    return product;
//O(1)时间
//    if (n == 2) return 1;
//    if (n == 3) return 2;
//    int num_3 = (int)n/3;
//    int remainder = n % 3;
//    if (remainder == 1) {
//        remainder = 4;
//        num_3 --;
//    } else if (remainder == 0)
//        remainder = 1;
//    return (int)Math.pow(3, num_3) * remainder;
}
int main()
{
    cout<<integerBreak(2)<<endl;
    return 0;
}









