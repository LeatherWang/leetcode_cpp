
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

int dfs(vector<int>& price, vector<vector<int>>& special, int index, vector<int> needs)
{
    if(special.size() == index)
    {
        int tepNum=0;
        for(int i=0; i<needs.size(); i++)
            tepNum += needs[i]*price[i];
        return tepNum;
    }
    vector<int> myvec;
    for(int j=0;;j++)
    {
        myvec.push_back(dfs(price, special, index+1, needs) +
                        special[index][special[index].size()-1]*j);
        int i=0;
        for(; i<needs.size(); i++)
            if(needs[i] - special[index][i] < 0)
                break;
        if(i == needs.size())
            break;
        for(int i=0; i<needs.size(); i++)
            needs[i] -= special[index][i];
    }
    sort(myvec.begin(), myvec.end());
    return myvec[0];
}
int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
{
    if(price.empty() || special.empty() || needs.empty())
        return 0;
    return dfs(price, special, 0, needs);
}

int main()
{
    return 0;
}









