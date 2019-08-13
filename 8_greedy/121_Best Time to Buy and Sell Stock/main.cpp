
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
int maxProfit(vector<int>& prices)
{
    // 第一种方案
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
    // discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems
    int T_i10=0, T_i11=INT_MIN;
    for(auto price:prices)
    {
        T_i10 = max(T_i10, T_i11+price);
        T_i11 = max(T_i11, -price);
    }
    return T_i10;

    if(prices.empty())
        return 0;

    // 第二种方案
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
    // discuss/108871/2-solutions-2-states-DP-solutions-clear-explanation!
    if(prices.empty())
        return 0;
    int days = prices.size();
    vector<int> buy(days);
    vector<int> sell(days);
    buy[0] = -prices[0];
    for(int i=1; i<days; i++)
    {
        buy[i] = max(buy[i-1], 0-prices[i]);
        sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
    }
    return sell[days-1];
}

int main()
{
    return 0;
}









