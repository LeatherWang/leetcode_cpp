
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
#include <set>

using namespace std;

vector<string> findAndReplacePattern(vector<string>& words, string pattern)
{
    vector<string> res;
    unordered_map<char ,char> mapTo;
    unordered_map<char ,char> mapFrom;
    for(string str:words)
    {
        mapTo.clear();
        mapFrom.clear();
        int i=0;
        for(; i<str.size(); i++)
        {
            if(mapTo.find(str.at(i)) != mapTo.end())
            {
                if(mapTo[str.at(i)] != pattern.at(i))
                    break;
            }
            else
                mapTo[str.at(i)] = pattern.at(i);

            if(mapFrom.find(pattern.at(i)) != mapFrom.end())
            {
                if(mapFrom[pattern.at(i)] != str.at(i))
                    break;
            }
            else
                mapFrom[pattern.at(i)] = str.at(i);
        }
        if(i == str.size())
            res.push_back(str);
    }
    return res;
}


// 排名第一的算法
vector<string> findAndReplacePattern(vector<string>& words, string pattern)
{
    vector<string> res;
    for(string str:words)
    {
        int a[26]={0}, b[26]={0};
        int i = 0;
        for(; i<str.size(); i++)
        {
            if(a[str.at(i)-'a'] != b[pattern.at(i)-'a'])
                break;
            else
                a[str.at(i)-'a'] = b[pattern.at(i)-'a'] = i+1;
        }
        if(i == str.size())
            res.push_back(str);
    }
    return res;
}

int main()
{
    return 0;
}









