
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
int findContentChildren(vector<int>& g, vector<int>& s)
{
    int index_g=0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] >= g[index_g])
        {
            index_g++;
            if(index_g >= g.size())
                return index_g;
        }
    }
    return index_g;
}

int main()
{
    return 0;
}









