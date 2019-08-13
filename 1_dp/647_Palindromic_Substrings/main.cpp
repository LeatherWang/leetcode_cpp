
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
#include <ctime>

using namespace std;
int countSubstrings(string s)
{
    int leftIndex, rightIndex;
    int res=0;
    for(int i=0; i<s.size(); i++)
    {
        leftIndex = rightIndex = i;
        for(;(s[leftIndex] == s[rightIndex]) && leftIndex>=0 && rightIndex <s.size();)
        {
            res++;
            leftIndex--; rightIndex++;
        }
        leftIndex = i;
        rightIndex = i+1;
        for(;(s[leftIndex] == s[rightIndex]) && leftIndex>=0 && rightIndex <s.size();)
        {
            res++;
            leftIndex--; rightIndex++;
        }
    }
    return res;
}
int main()
{
    cout<<countSubstrings("abc")<<endl;
    return 0;
}









