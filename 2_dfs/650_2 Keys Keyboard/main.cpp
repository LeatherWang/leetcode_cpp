
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

using namespace std;

//We look for a divisor d so that we can make d copies of (n / d) to get n
//The process of making d copies takes d steps (1 step of Copy All and d - 1 steps of Paste)
int minSteps(int n)
{
    int res = 0;
    for(int i =2; i<=n; i++)
    {
        while(n%i == 0)
        {
            res += i;
            n /= i;
        }
    }
    return res;
}

int main()
{
    return 0;
}









