
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
string longestCommonPrefix(vector<string>& strs)
{
    if(strs.size() == 0)
        return string("");
    else if(strs.size() == 1)
            return strs[0];
    string commonStr=string(""), firstString;
    firstString = strs[0];
    for(int i=0; i<firstString.size(); i++)
    {
        for(int index=1; index<strs.size(); index++)
        {
            if(i < strs[index].size())
            {
                if(firstString.at(i) != strs[index].at(i))
                {
                    return commonStr;
                }
            }
            else
            {
                return commonStr;
            }
        }
        commonStr.push_back(firstString.at(i));
    }
    return commonStr;
}

int main()
{
    vector<string> mystr{"flower", "flow", "flight"};
    cout<<"longestCommonPrefix: "<<longestCommonPrefix(mystr)<<endl;
    return 0;
}









