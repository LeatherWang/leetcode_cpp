
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <math.h>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int lengthOfLongestSubstring_myself(string s)
{
    unordered_map<char,int> mapStrIndex;
    int lengthMax=0;
    for(int i=0; i<s.size(); i++)
    {
        auto iterFind = mapStrIndex.find(s.at(i));
        if(iterFind == mapStrIndex.end())
        {
            //cout<<"1: "<<s.at(i)<<endl;
            mapStrIndex.insert(pair<char, int>(s.at(i), i));

            if(mapStrIndex.size() > lengthMax)
                lengthMax = mapStrIndex.size();
            //cout<<"lengthMax: "<<lengthMax<<endl;
        }
        else
        {
            //cout<<"2: "<<s.at(i)<<endl;
            for(auto iter1=mapStrIndex.begin(); iter1 != mapStrIndex.end(); )
            {
                if(iter1->second < iterFind->second)
                    iter1 = mapStrIndex.erase(iter1); /** @attention map擦除的时候必须要这么做!!*/
                else
                    iter1++;
            }

            mapStrIndex[s.at(i)] = i;
        }
    }
    cout<<"final lengthMax: "<<lengthMax<<endl;
    return lengthMax;
}

// 方法一: 暴力法
int lengthOfLongestSubstring_violence(string s)
{
    int i=0, j=0;
    int n = s.size();
    int lengthMax=0;
    bool break_flag=false;
    for(; i < n; i++)
    {
        for(j=i+1; j <= n; j++)
        {
            unordered_set<char> setTemp;
            for(int k=i; k<j; k++)
            {
                if(setTemp.find(s.at(k)) == setTemp.end())
                {
                    lengthMax = max(lengthMax, k-i+1);
                    setTemp.insert(s.at(k));
                }
                else
                {
                    break_flag = true;
                    break;
                }
            }
            if(break_flag)
            {
                break_flag = false;
                break;
            }
        }
    }
    cout<<"lengthOfLongestSubstring_violence: "<<lengthMax<<endl;
    return lengthMax;
}

// 方法二: 滑动窗口法
// 滑动窗口是数组/字符串问题中常用的抽象概念。
// 窗口通常是在数组/字符串中由开始和结束索引定义的一系列元素的集合，即 [i,j)（左闭，右开）
int lengthOfLongestSubstring_slidingwin_set(string s)
{
    unordered_set<char> setStr;
    int lengthMax=0;
    for(int i=0, j=0; j<s.size() && i<s.size(); )
    {
        if(setStr.find(s.at(j)) == setStr.end())
        {
            setStr.insert(s.at(j++));
            lengthMax = max(lengthMax, j-i);
        }
        else
            setStr.erase(s.at(i++));
    }

    cout<<"lengthOfLongestSubstring_slidingwin_set: "<<lengthMax<<endl;
    return lengthMax;
}

// 方法三: 优化的滑动窗口法
int lengthOfLongestSubstring_slidingwin_map(string s)
{
    unordered_map<char,int> mapStrIndex;
    int lengthMax=0;
    for(int i=0, j=0; j<s.size(); j++)
    {
        if(mapStrIndex.find(s.at(j)) != mapStrIndex.end())
        {
            i = max(mapStrIndex[s.at(j)], i);
        }
        lengthMax = max(lengthMax, j+1 - i);
        mapStrIndex[s.at(j)] = j+1;
    }
    cout<<"lengthOfLongestSubstring_slidingwin_map: "<<lengthMax<<endl;
    return lengthMax;
}

// abcabcbb abc  3
// bbbbb    b    1
// pwwkew   wke  3
// abfcba
int main()
{
    string mystring="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!";
    lengthOfLongestSubstring_myself(mystring);
    lengthOfLongestSubstring_slidingwin_set(mystring);
    lengthOfLongestSubstring_slidingwin_map(mystring);
    lengthOfLongestSubstring_violence(mystring); //当字符串很大时，耗时明显，O(n^3)

    return 0;
}
