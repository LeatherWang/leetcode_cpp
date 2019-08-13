
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <math.h>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int findMaxSubStr(int left, int right, string &str)
{
    for(;left>=0 && right<str.size();)
    {
        if(str.at(left) != str.at(right))
            break;
        left--;
        right++;
    }
    return right-left-1;
}

string longestPalindrome(string s)
{
    int startIndex=0, endIndex=0;
    for(int i=0; i<s.size(); i++)
    {
        int length,length1, length2;
        length1 = findMaxSubStr(i, i, s);
        length2 = findMaxSubStr(i, i+1, s);
        length = max(length1, length2);
        if(length > (endIndex - startIndex+1))
        {
            startIndex = i - (length-1)/2;
            endIndex = i + length/2;
        }
        cout<<endIndex - startIndex+1<<endl;
    }
    string longestSub = s.substr(startIndex, endIndex - startIndex+1);
    cout<<longestSub<<endl;
    return longestSub;
}


int main()
{
    string mtstr="babad";
    longestPalindrome(mtstr);
    return 0;
}
