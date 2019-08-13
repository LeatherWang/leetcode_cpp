
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
bool isPalindrome(string& s, int start, int end)
{
    while(start<end)
        if(s[start++] != s[end--]) return false;
    return true;
}

void backTracking(string& s, int start, vector<vector<string>> &res, vector<string>& tmpVec)
{
    if(start == s.size())
    {
        res.push_back(tmpVec);
        return;
    }
    for(int i=start; i<s.size(); i++)
    {
        if(isPalindrome(s, start, i))
        {
            tmpVec.push_back(s.substr(start, i-start+1));
            backTracking(s, i+1, res, tmpVec);
            tmpVec.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> tmpVec;
    backTracking(s, 0, res, tmpVec);
    return res;
}

int main()
{
    return 0;
}









