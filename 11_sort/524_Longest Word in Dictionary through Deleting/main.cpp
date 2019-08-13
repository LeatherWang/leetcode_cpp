
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

// 输入:
// s = "abpcplea", d = ["ale","apple","monkey","plea"]
// 输出:
//"apple"
string findLongestWord(string s, vector<string>& d)
{
    vector<pair<int, int>> pairRes;
    for(int k=0; k<d.size(); k++)
    {
        int i=0;
        for(auto ch:s)
            if(ch == d[k].at(i))
            {
                if(++i == d[k].size())
                    break;
            }
        if(i == d[k].size())
            pairRes.push_back(make_pair(k, i)); //No, size
    }
    if(!pairRes.empty())
    {
        sort(pairRes.begin(), pairRes.end(), [d](const pair<int ,int> &a, const pair<int, int> &b)
        {return a.second>b.second || (a.second == b.second && d[a.first] < d[b.first]);});
        return d[pairRes[0].first];
    }
    return string();
}

string findLongestWord_1(string s, vector<string>& d)
{
    if(!s.size() || !d.size())
        return string();

    auto cmp = [](const string &a, const string &b){
        return a.size() > b.size() || (a.size() == b.size() && a<b);
    };
    sort(d.begin(), d.end(), cmp);

    for(string str:d)
    {
        int i=0;
        for(char ch:s)
            if(ch == str.at(i))
            {
                if(++i == str.size())
                    break;
            }
        if(i == str.size())
            return str;
    }
    return string();
}

// 排名第一的算法实现

string findLongestWord(string s, vector<string>& d) {
        string longest_str = "";
        for (auto t : d) {
            if (longest_str.size() > t.size() ||
                    (longest_str.size() == t.size() && longest_str < t))
                continue;
            if (isValid(s, t)) longest_str = t;
        }
        return longest_str;
    }

    bool isValid(const string &s1, const string &s2) {
        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size()) if (s1[i++] == s2[j]) ++j;
        return j == s2.size();
    }

int main()
{
    return 0;
}









