
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
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)
int maxProfit(vector<int>& prices)
{
    if(prices.empty())
        return 0;
    int days = prices.size();
    vector<int> buy(days);
    vector<int> sell(days);
    buy[0] = -prices[0];
    sell[0] = 0;
    for(int i=1; i<days; i++)
    {
        buy[i] = max(buy[i-1], (i<2?0:sell[i-2])-prices[i]);
        sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
    }
    return sell[days-1];
}

int main()
{
    return 0;
}









