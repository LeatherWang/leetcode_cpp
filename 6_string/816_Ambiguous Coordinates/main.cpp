
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

//In sub functon f(S)
//if S == "": return []
//if S == "0": return [S]
//if S == "0XXX0": return []
//if S == "0XXX": return ["0.XXX"]
//if S == "XXX0": return [S]
//return [S, "X.XXX", "XX.XX", "XXX.X"...]
vector<string> f(string str)
{
    vector<string> res;
    if(str.empty())
        return res;
    if(str[0] == '0')
    {
        if(str.size() == 1)
        {
            res.push_back(str);
            return res;
        }

        if(str.back() == '0')
            return res;

        res.push_back(string("0.")+str.substr(1, str.size()-1));
        return res;
    }

    if(str.back() == '0')
    {
        res.push_back(str);
        return res;
    }

    res.push_back(str);
    for(int i=0; (i+1)< str.size(); i++)
        res.push_back(str.substr(0, i+1) + "." + str.substr(i+1, str.size()-i-1));
    return res;
}

vector<string> ambiguousCoordinates(string S)
{
    vector<string> res;
    string str = S.substr(1, S.size()-2);
    for(int i=0; (i+1)< str.size(); i++)
    {
        vector<string> vec1 = f(str.substr(0, i+1));
        vector<string> vec2 = f(str.substr(i+1, str.size()-i-1));
        for(int i=0; i<vec1.size(); i++)
        {
            for(int j=0; j< vec2.size(); j++)
            {
                res.push_back(string("(")+vec1[i] + ", " + vec2[j] + ")");
            }
        }
    }
    return res;
}

int main()
{
    return 0;
}









