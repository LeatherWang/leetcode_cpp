
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

bool lemonadeChange(vector<int>& bills)
{
    vector<int> myvec(3, 0);
    for(int i=0; i<bills.size(); i++)
    {
        switch (bills[i]) {
        case 5:
            myvec[0]++;
            break;
        case 10:
            if(--myvec[0]<0)
                return false;
            myvec[1]++;
            break;
        case 20:
            if(myvec[1] == 0)
            {
                myvec[0] -=3;
                if(myvec[0]<0)
                    return false;
            }
            else
            {
                --myvec[1];
                if(--myvec[0]<0)
                    return false;
            }
            myvec[2]++;
            break;
        default:
            break;
        }
    }
    return true;
}
int main()
{
    return 0;
}









