
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
    int profit=0;
    int a = 1<<30;
    int b=0;
    for(int i=0; i<prices.size(); i++)
    {
        if(prices[i] >= a || b)
        {
            if(prices[i] >= b)
            {
                b = prices[i];
                if(i==(prices.size()-1))
                    profit +=b-a;
            }
            else
            {
                profit +=b-a;
                a = prices[i];
                b = 0;
            }
        }
        else
        {
            a = prices[i];
            b = 0;
        }
    }
    return profit;
}

// 排名第一的算法
int maxProfit(vector<int>& prices) {
    int max = 0;
    for (int i = 1; i < prices.size(); ++i)
        if (prices[i] - prices[i - 1] > 0)
            max += prices[i] - prices[i - 1];
    return max;
}

// 新方法!!
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// discuss/108871/2-solutions-2-states-DP-solutions-clear-explanation!
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
        buy[i] = max(buy[i-1], sell[i-1]-prices[i]);
        sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
    }
    return sell[days-1];
}

int main()
{
    return 0;
}









