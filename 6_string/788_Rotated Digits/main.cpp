
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

int rotatedDigits(int N) {
    unordered_set<int> nonNum{3,4,7};
    unordered_set<int> diffNum{2,5,6,9};
    int res=0;
    vector<int> tmpVec(N+1, 0);
    for(int i=1; i<=N; i++)
    {
        int k=i;
        int remain = k%10;
        if(nonNum.find(remain) != nonNum.end())
        {
            tmpVec[i] = -1;
            continue;
        }

        k /= 10;
        if(tmpVec[k] == -1)
            tmpVec[i] = -1;
        else if(tmpVec[k] == 1 || diffNum.find(remain) != diffNum.end())
        {
            tmpVec[i] = 1;
            res++;
        }
    }
    return res;
}

int main()
{
    cout<<toGoatLatin("The quick brown fox jumped over the lazy dog")<<endl;
    return 0;
}









