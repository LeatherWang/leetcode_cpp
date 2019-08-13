
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
bool iterFind(vector<int>& piles, int yali, int lee, int head, int tail, bool whodo)
{
    if(head == tail)
    {
        if(yali > lee)
            return true;
        else
            return false;
    }

    if(whodo)
    {
        if(iterFind(piles, yali+piles[head], lee, head+1, tail, !whodo))
            return true;

        if(iterFind(piles, yali+piles[tail], lee, head, tail-1, !whodo))
            return true;
    }
    else
    {
        if(iterFind(piles, lee+piles[head], lee, head+1, tail, !whodo))
            return true;

        if(iterFind(piles, lee+piles[tail], lee, head, tail-1, !whodo))
            return true;
    }
}

bool stoneGame(vector<int>& piles)
{
    int yali=0, lee=0;
    int head=0, tail=piles.size()-1;
    bool whodo=true;
    return iterFind(piles, yali , lee, head, tail, whodo);
}

// haystack = "hello", needle = "ll"
// 3,2,10,4 1
//
int main()
{
    vector<int> myvec{5,3,4,5};
    cout<<stoneGame(myvec)<<endl;
    return 0;
}









