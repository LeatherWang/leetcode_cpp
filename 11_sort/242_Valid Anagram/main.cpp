
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

bool isAnagram(string s, string t)
{
    if(s.size() != t.size())
        return false;
    char sArr[26]={0};
    char tArr[26]={0};
    for(auto ch:s)
        sArr[ch-'a']++;
    for(auto ch:t)
        tArr[ch-'a']++;

    for(int i=0; i<26; i++)
        if(sArr[i] != tArr[i])
            return false;
    return true;
}

int main()
{
    return 0;
}









