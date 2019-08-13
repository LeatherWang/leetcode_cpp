
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
// 输入:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
// 输出:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people)
{
    auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
                    { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
    sort(people.begin(), people.end(), comp);
    vector<pair<int, int>> res;
    for (auto& p : people)
        res.insert(res.begin() + p.second, p);
    return res;
}

int main()
{
    return 0;
}









