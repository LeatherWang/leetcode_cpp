
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

int maxProfit(vector<int>& prices, int fee)
{
    int n=prices.size();
    if(prices.empty())
        return 0;
    vector<int> sell(n, 0);
    vector<int> buy(n, 0);
    buy[0] = 0-prices[0]-fee;
    for(int i=1; i<n ; i++)
    {
        buy[i] = max(buy[i-1], sell[i-1]-prices[i]-fee);
        sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
    }
    return sell.back();
}

int main()
{

    return 0;
}









