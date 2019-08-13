
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

string getPermutation(int n, int k)
{
    string res;
    int mul=1;
    int index, remain;
    vector<bool> vis(n, false);
    for(int i=1; i<n; i++)
        mul *=i;
    remain = --k;

    for(int i=n-1; i>0; --i)
    {
        index = remain/mul; //所以从0开始
        remain %=mul;
        mul /= i;
        int j=0;
        for(int m=0; m<index+1; j++)
        {
            if(!vis[j])
                m++;
        }
        res +=to_string(j);
        vis[--j] = true;
    }

    int j=0;
    for(int m=0; m<1; j++)
    {
        if(!vis[j])
            m++;
    }
    res +=to_string(j);
    cout<<res<<endl;
    return res;
}
int main()
{
    getPermutation(4,3);
    return 0;
}









