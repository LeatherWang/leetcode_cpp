
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
clock_t start, finish;

int bitMapList[16];
vector<int> countBits(int num)
{
//    for(int i=0; i < 16; i++)
//        bitMapList[i] =
    vector<int> myvec(num+1);
    for(int i=0; !(i>num); i++)
    {
        myvec[i] = __builtin_popcount(i);
    }
    return myvec;
}

// 递归法
vector<int> countBits(int num)
{
    vector<int> myvec(num+1, 0);
    for(int i=0; i<num ; i++)
    {
        if(i%2) myvec[i+1] = myvec[i]+1;
        else myvec[i+1] = myvec[i/2+1];

        // 下面一步也能实现
        //myvec[i+1] = myvec[i/2] + i%2;
    }
    return myvec;
}

int main()
{
    start = clock();
    countBits(1000);
    finish = clock();
    cout << (double)(finish - start) / (double)(CLOCKS_PER_SEC)  << " s" << endl;

    return 0;
}









