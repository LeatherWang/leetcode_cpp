
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

string toGoatLatin(string S) {
    string str = "aeiouAEIOU";
    unordered_set<char> myset(str.begin(), str.end());
    string res;
    int counter = 0;
    char b=0;
    if(myset.find(S.at(0)) == myset.end())
        b = S.at(0);
    else
        res.push_back(S.at(0));
    for(int i=1; i<S.size(); i++)
    {
        if(S.at(i-1) == ' ')
        {
            if(myset.find(S.at(i)) == myset.end())
            {
                b = S.at(i);
                continue;
            }
        }
        if(S.at(i) == ' ')
        {
            if(b)
                res.push_back(b);
            b = 0;
            res +="ma";
            counter++;
            for(int j=0; j<counter; j++)
                res.push_back('a');
        }
        res.push_back(S.at(i));
    }
    if(b)
        res.push_back(b);
    res +="ma";
    counter++;
    for(int j=0; j<counter; j++)
        res.push_back('a');
    return res;
}

int main()
{
    cout<<toGoatLatin("The quick brown fox jumped over the lazy dog")<<endl;
    return 0;
}









