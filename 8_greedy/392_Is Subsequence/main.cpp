
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
bool isSubsequence(string s, string t)
{
//    vector<vector<int>> myStatus(t.size()+1, vector<int>(s.size()+1, 0));
//    for(int i=1; i<myStatus.size(); i++)
//    {
//        for(int j=1; j<myStatus[0].size(); j++)
//        {
//            if(s.at(j-1) == t.at(i-1))
//            {
//                myStatus[i][j] = myStatus[i-1][j-1] + 1;
//                cout<<j-1<<" "<<s.at(j-1)<<endl;
//            }
//            else
//                myStatus[i][j] = max(myStatus[i-1][j], myStatus[i][j-1]);
//        }
//        if(myStatus[i][j] == s.size())
//            return true;
//    }
//    cout<<myStatus[t.size()][s.size()]<<endl;
//    return false;

    if(s.empty())
        return true;
    int start=0;
    for(int i=0; i<s.size(); i++)
    {
        int j=start;
        for(; j<t.size(); j++)
        {
            if(s.at(i) == t.at(j))
            {
                if(i == s.size()-1)
                    return true;
                start = j+1;
                break;
            }
        }
        if(j==t.size())
            return false;
    }
    return false;
}

// 排名第一的算法
bool isSubsequence(string s, string t)
{
    if(s.length()==0) return true;
    int sp,tp;
    sp=tp=0;
    while(tp!=t.length()){
        if(s[sp]==t[tp++])
            sp++;
        if(sp==s.length()) return true;
    }
    return false;
}
int main()
{
    cout<<isSubsequence("asb", "sdasbtcmn")<<endl;
    return 0;
}









