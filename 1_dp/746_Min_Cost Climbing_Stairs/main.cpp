
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

using namespace std;
int minCostClimbingStairs(vector<int>& cost)
{
    if(cost.empty()) return 0;
    vector<int> myStatus(cost.size()+1, 0);
    myStatus[0] = cost[0];
    myStatus[1] = cost[1];
    for(int i=2; i<=cost.size(); i++)
    {
        myStatus[i] = ((i!=cost.size())?cost[i]:0) + min(myStatus[i-1], myStatus[i-2]);
    }
    return myStatus[cost.size()];
}
// 输入: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
// 输出: 6
// 解释: 最低花费方式是从cost[0]开始，逐个经过那些1，跳过cost[3]，一共花费6。
int main()
{
    vector<int> myvec{0,1,1,0};
    cout<<minCostClimbingStairs(myvec)<<endl;
    return 0;
}









