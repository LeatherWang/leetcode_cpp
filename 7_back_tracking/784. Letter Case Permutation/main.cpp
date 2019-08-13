
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

void backTracking(const string& S, int index, vector<string>& res, string curStr)
{
    if(index >= S.size())
    {
        res.push_back(curStr);
        return;
    }

    curStr.push_back(S.at(index));
    backTracking(S, index+1, res, curStr);
    if(islower(S.at(index)))
    {
        curStr.at(index) = S.at(index)&(-33); //! @attention 大小写转换
        backTracking(S, index+1, res, curStr);
    }
    else if(isupper(S.at(index)))
    {
        curStr.at(index) = S.at(index)|32;
        backTracking(S, index+1, res, curStr);
    }
    curStr.pop_back();
}
vector<string> letterCasePermutation(string S)
{
    vector<string> res;
    backTracking(S, 0, res, "");
    return res;
}
int main()
{
    return 0;
}









