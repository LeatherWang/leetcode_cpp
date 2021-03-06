
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

int numSpecialEquivGroups(vector<string>& A)
{
//    set<vector<set<char>>> resSet;
//    for(string str:A)
//    {
//        vector<set<char>> tmpVec(2, set<char>());
//        for(int i=0; i<str.size(); i++)
//            tmpVec[i%2].insert(str.at(i));
//        resSet.insert(tmpVec);
//    }
//    return resSet.size();

    set<vector<int>> res;
    vector<int> tmpVec(52,0);
    for(string str:A)
    {
        fill(tmpVec.begin(), tmpVec.end(), 0);
        for(int i=0; i< str.size(); i++)
        {
            tmpVec[str.at(i)-'a'+(i%2?26:0)]++;
        }
        res.insert(tmpVec);
    }
    return tmpVec.size();
}

int main()
{
    return 0;
}









