
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
#include <queue>

using namespace std;

int countNumbersWithUniqueDigits(int n)
{
    if(!n)
        return 0;
    int res = 10;
    int lastCounter=9;
    for(int i=1; i < n; i++)
    {
        lastCounter = lastCounter * (10-i);
        res += lastCounter;
    }
    return res;
}

int main()
{
    return 0;
}









