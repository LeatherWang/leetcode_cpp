
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

bool dfs(vector<vector<int>>& rooms, unordered_set<int>& setKeys, int myKey)
{
    if(setKeys.size() == rooms.size())
        return true;
    for(int i=0; i<rooms[myKey].size(); i++)
    {
        if(setKeys.find(rooms[myKey][i]) == setKeys.end())
        {
            setKeys.insert(rooms[myKey][i]);
            if(dfs(rooms, setKeys, rooms[myKey][i]))
                return true;
        }
    }
    return false;
}

bool canVisitAllRooms(vector<vector<int>>& rooms)
{
    if(!rooms.size())
        return true;
    unordered_set<int> setKeys;
    setKeys.insert(0);
    return dfs(rooms, setKeys, 0);
}

int main()
{
    return 0;
}









