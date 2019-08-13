
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
//输入: S = "ababcbacadefegdehijhklij"
//输出: [9,7,8]
//解释:
//划分结果为 "ababcbaca", "defegde", "hijhklij"。

struct Letter{
    char val;
    int start;
    int end;
    bool operator < (const Letter &l) const {return start < l.start;}
    Letter(char x, int index):val(x), start(index), end(index){}
};
typedef Letter * pLetter;

vector<int> partitionLabels(string S)
{
    vector<int> res;
    if(S.empty())
        return res;
    map<char, pLetter> mapList;
    for(int i=0; i<S.size(); i++)
    {
        map<char, pLetter>::iterator iter = mapList.find(S.at(i));
        if(iter == mapList.end())
        {
            pLetter pItem = new Letter(S.at(i), i);
            mapList.insert(make_pair(S.at(i), pItem));
        }
        else
        {
            (*iter).second->end = i;
        }
    }

    vector<Letter> myvec;
    for(auto item:mapList)
        myvec.push_back(*item.second);
    sort(myvec.begin(), myvec.end());

    int startIndex=myvec[0].start, endIndex=myvec[0].end;
    for(int i=0;i<myvec.size();i++)
    {
        if(startIndex < myvec[i].start && myvec[i].start<endIndex)
            endIndex = max(endIndex, myvec[i].end);
        else if(myvec[i].start > endIndex)
        {
            res.push_back(endIndex-startIndex+1);
            cout<<res.back()<<endl;
            startIndex = myvec[i].start;
            endIndex = myvec[i].end;
        }
    }
    res.push_back(endIndex-startIndex+1);
    cout<<res.back()<<endl;
    return res;
}

// 排名第一的算法
vector<int> partitionLabels(string S) {
    int size=S.size();
    vector<int> start(26,-1);
    vector<int> end(26,-1);
    for(int i=0;i<size;i++)
    {
        if(start[S[i]-'a']<0)
        {
            start[S[i]-'a']=i;
        }
        end[S[i]-'a']=i;
    }
    map<int,int> region;
    for(int i=0;i<26;i++)
    {
        if(start[i]<0) continue;
        region[start[i]] = end[i];
    }
    map<int,int>::iterator it;
    int start_pos=-1,end_pos=-1;
    vector<int> result;
    for(it=region.begin();it!=region.end();it++)
    {
        if (it->first > end_pos)
        {
            if (end_pos>=0)
            {
                result.push_back(end_pos-start_pos+1);
            }
            start_pos = it->first;
            end_pos = it->second;
        }
        else
        {
            start_pos = min(start_pos,it->first);
            end_pos = max(end_pos,it->second);
        }
    }
    if(end_pos>=start_pos)
    {
        result.push_back(end_pos-start_pos+1);
    }
    return result;
}

int main()
{
    partitionLabels("caedbdedda");
    return 0;
}









