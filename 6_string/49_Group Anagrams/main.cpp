
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
//输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
//输出:
//[
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//]
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector<vector<string>> res;
    map<vector<int>, int> mapList;
    vector<int> tmpVec = vector<int>(26, 0);
    for(int i=0; i< strs.size(); i++)
    {
        fill(tmpVec.begin(), tmpVec.end(), 0);
        for(char ch:strs[i])
            tmpVec[ch-'a']++;

        auto iter = mapList.find(tmpVec);
        if(iter != mapList.end())
        {
            res[iter->second].push_back(strs[i]);
        }
        else
        {
            mapList[tmpVec] = res.size();
            res.push_back(vector<string>{strs[i]});
        }
    }
    return res;
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector<vector<string> > res;
    unordered_map<string, int > m;
    for(auto str : strs)
    {
        string t = str;
        sort(t.begin(),t.end());
        auto iter = m.find(t);
        if(iter != m.end())
            res[iter->second].push_back(str);
        else
        {
            m[t] = res.size();
            res.push_back(vector<string>{str});
        }
    }

    return res;
}

int main()
{
    return 0;
}









