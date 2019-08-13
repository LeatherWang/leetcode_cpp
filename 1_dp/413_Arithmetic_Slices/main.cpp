
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

int numberOfArithmeticSlices(vector<int>& A)
{
    vector<int> mystatus(A.size(), 0);
    int tempCounter=0;
    int maxNum=0;
    for(int i=2; i< A.size(); i++)
    {
        if((A[i]+A[i-2]) == (2*A[i-1]))
        {
            tempCounter++;
        }
        else
        {
            maxNum +=(tempCounter+1)*tempCounter/2;
            tempCounter = 0;
        }
    }
    if(tempCounter != 0)
        maxNum +=(tempCounter+1)*tempCounter/2;
    return maxNum;
}

// A = [1, 2, 3, 4]
// 返回: 3, A 中有三个子等差数组: [1, 2, 3], [2, 3, 4] 以及自身 [1, 2, 3, 4]。
int main()
{   vector<int> myvec{1, 2, 3, 4};
    cout<<numberOfArithmeticSlices(myvec)<<endl;
    return 0;
}









