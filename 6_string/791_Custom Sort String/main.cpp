
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

//输入:
//S = "cba"
//T = "abcd"
//输出: "cbad"
string customSortString(string S, string T)
{
    map<char,int> mapList;
    int i=1;
    for(char ch='a'; ch<='z'; ch++)
        mapList[ch] = 0;
    for(char ch:S)
        mapList[ch] = i++;
    vector<char> vecTmp(T.begin(), T.end());
    auto cmp = [mapList](const char & a, const char &b){
        return mapList.find(a)->second<mapList.find(b)->second;
    };
    sort(vecTmp.begin(), vecTmp.end(), cmp);
    string res(vecTmp.begin(), vecTmp.end());
    cout<<res<<endl;
    return res;
}

// 排名第一的算法
string customSortString(string S, string T) {
    string ans;
    for (auto &elem:S)
    {
        int p = T.find(elem);
        while (p != T.npos)
        {
            ans.insert(ans.end(), elem);
            T.erase(p, 1);
            p = T.find(elem);
        }
    }
    ans += T;
    return ans;
}

int main()
{
    customSortString("cba", "abcd");
    return 0;
}









