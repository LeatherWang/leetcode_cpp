
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

vector<int> grayCode(int n)
{
    vector<int> res;
    for(int i=0; i < 1<<n; i++)
        res.push_back(i^i>>1);
    return res;
}

int main()
{
    return 0;
}









