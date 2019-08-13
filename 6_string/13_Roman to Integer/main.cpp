
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
int romanToInt(string s)
{
    map<char, int> mapList{{'I',1},{'V', 5}, {'X', 10}, {'L', 50},
                           {'C', 100}, {'D', 500}, {'M', 1000}};
    if(s.empty())
        return 0;
    int res = mapList[s.at(0)];
    for(int i=1; i< s.size(); i++)
    {
        if(s.at(i-1)=='I' && (s.at(i) == 'V' || s.at(i) == 'X'))
            res -= mapList['I']*2;
        if(s.at(i-1)=='X' && (s.at(i) == 'L' || s.at(i) == 'C'))
            res -= mapList['X']*2;
        if(s.at(i-1)=='C' && (s.at(i) == 'D' || s.at(i) == 'M'))
            res -= mapList['C']*2;
        res += mapList[s.at(i)];
    }
    return res;
}
int main()
{
    myAtoi("-+1");
    return 0;
}









