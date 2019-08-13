
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

using namespace std;

int strStr(string haystack, string needle)
{
    if(needle.empty())
        return 0;
    int n = haystack.size()-needle.size()+1;
    for(int index=0; index<n; index++)
    {
//        int j=0;
//        for(; j<needle.size(); j++)
//        {
//            if(needle.at(j) != haystack.at(index+j))
//                break;
//        }
//        if(j == needle.size())
//        {
//            return index;
//        }

        if(haystack.substr(index, needle.size()) == needle)
            return index;
    }
    return -1;
}

// haystack = "hello", needle = "ll"
int main()
{
    cout<<strStr("mississippi","mississippi")<<endl;
    return 0;
}









