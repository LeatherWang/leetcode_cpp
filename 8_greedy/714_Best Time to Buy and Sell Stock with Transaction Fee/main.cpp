
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
// 输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
// 输出: 8
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// discuss/108871/2-solutions-2-states-DP-solutions-clear-explanation!
int maxProfit(vector<int>& prices, int fee)
{
    if(prices.empty())
        return 0;
    int days = prices.size();
    vector<int> buy(days);
    vector<int> sell(days);
    buy[0] = -prices[0]-fee;
    sell[0] = 0;
    for(int i=1; i<days; i++)
    {
        buy[i] = max(buy[i-1], sell[i-1]-prices[i]-fee);
        sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
    }
    return sell[days-1];
}

int main()
{
    return 0;
}









