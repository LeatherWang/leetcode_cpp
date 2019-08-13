
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

bool dfs(string bottom,  int index, string nextLevel, unordered_map<string, vector<char>>& mapList)
{
    if(bottom.size() == 1 && index == 0)
        return true;

    if(index >= (bottom.size()-1))
    {
        if(dfs(nextLevel, 0, "", mapList))
            return true;
    }

    if(mapList.find(bottom.substr(index, 2)) == mapList.end())
        return false;
    else
    {
        for(char ch:mapList[bottom.substr(index, 2)])
        {
            nextLevel.push_back(ch);
            if(dfs(bottom, index+1, nextLevel, mapList))
                return true;
            nextLevel.pop_back();
        }
    }
    return false;
}

bool pyramidTransition(string bottom, vector<string>& allowed)
{
    if(bottom.empty() || allowed.empty())
        return false;
    unordered_map<string, vector<char>> mapList;
    for(string str:allowed)
    {
        mapList[str.substr(0,2)].push_back(str[2]);
    }
    return dfs(bottom, 0, "", mapList);
}

//  bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
int main()
{
    string bottom = "XYr";
    vector<string> allowed{"XYD", "YZE", "DEA", "FFF"};
    cout<<pyramidTransition(bottom, allowed)<<endl;
    return 0;
}









