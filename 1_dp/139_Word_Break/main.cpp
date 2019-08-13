
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

int maxWordSize;
unordered_set<string> setWord;
vector<int> myStatus;
bool haveWord(string &s, int beginIndex)
{
    if(beginIndex == s.size())
        return true;
    for(int i=1; i<=maxWordSize; i++)
    {
        if((beginIndex+i) > s.size())
            return false;
        if(setWord.find(s.substr(beginIndex, i)) != setWord.end())
        {
            //cout<<s.substr(beginIndex, i)<<endl;
            if(myStatus[beginIndex] == 0)
                return false;
            else if(myStatus[beginIndex] == 1)
                return true;
            if(haveWord(s, beginIndex+i))
            {
                myStatus[beginIndex] = 1;
                return true;
            }
        }
    }
    myStatus[beginIndex] = 0;
    return false;
}

bool wordBreak(string s, vector<string>& wordDict)
{
    if(s.empty() || wordDict.empty()) return false;
    myStatus = vector<int >(s.size(),-1);
    maxWordSize = 0;
    for(string str:wordDict)
    {
        if(str.size() > maxWordSize)
            maxWordSize = str.size();
        setWord.insert(str);
    }
    return haveWord(s, 0);
}
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
bool wordBreak_recurrence(string s, vector<string>& wordDict)
{
    unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (size_t i = 1; i <= s.size(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (dp[j]) {
                if( dict.find(s.substr(j, i - j)) != dict.end()) //! @attention 与求最长上升子序列一样的过程
                {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    return dp[s.size()];
}

int main()
{
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> mystr{"a","ab","aaaaaaaaaaaaaaaa"};
    cout<<wordBreak(s, mystr)<<endl;
    cout<<s.substr(0,1)<<endl;
    return 0;
}









