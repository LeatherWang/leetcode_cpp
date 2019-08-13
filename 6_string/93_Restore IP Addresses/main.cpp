
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
//输入: "25525511135"
//输出: ["255.255.11.135", "255.255.111.35"]

void dfs_1(vector<string>& res, int index, vector<int>& vecTmp, string &s)
{
    if(vecTmp.size() == 4)
    {
        if(index == s.size())
        {
            string str;
            for(int a:vecTmp)
                str += to_string(a)+".";
            str.pop_back();
            res.push_back(str);
            return;
        }
        else
            return;
    }

    if(index > (s.size()-1))
        return;

    if(s[index] == '0')
    {
        vecTmp.push_back(0);
        dfs(res, index+1, vecTmp, s);
        vecTmp.pop_back();
    }
    else if(vecTmp.size() == 3)
    {
        if((s.size()-index)>3)
            return;
        int a = stoi(s.substr(index, s.size()-index));
        if(a>255)
            return;
        vecTmp.push_back(a);
        dfs(res, s.size(), vecTmp, s);
        vecTmp.pop_back();
    }
    else
    {
        for(int i=1; i<4; i++)
        {
            if(index+i > s.size())
                break;
            int a = stoi(s.substr(index, i));
            if(a>255)
                break;
            vecTmp.push_back(a);
            dfs(res, index+i, vecTmp, s);
            vecTmp.pop_back();
        }
    }
}
vector<string> restoreIpAddresses(string s)
{
    vector<string> res;
    vector<int> vecTmp;
    dfs(res, 0, vecTmp, s);
    return res;
}

int main()
{
    restoreIpAddresses("0279245587303");
    return 0;
}









