
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
vector<vector<int>> myStatus;
int iterFind(vector<vector<int>>& triangle, int i, int j)
{
    if(j > i) return 0;
    if(i == triangle.size())
        return 0;
    if(myStatus[i][j] != -1)
        return myStatus[i][j];

    myStatus[i][j] = (min(iterFind(triangle, i+1, j), iterFind(triangle, i+1, j+1))+
                     triangle[i][j]);
    return myStatus[i][j];
}

// 递归实现
int minimumTotal_iter(vector<vector<int>>& triangle)
{
    myStatus = vector<vector<int>>(triangle.size(),vector<int>(triangle.size(), -1));
    return iterFind(triangle, 0, 0);
}

// 递推实现
int minimumTotal(vector<vector<int>>& triangle)
{
    int i = triangle.size()-2;
    for(;!(i < 0); i--)
    {
        for(int j=0; !(j>i); j++)
        {
            triangle[triangle.size()-1][j] = triangle[i][j]+
                    min(triangle[triangle.size()-1][j], triangle[triangle.size()-1][j+1]);
        }
    }
    return triangle[triangle.size()-1][0];
}

int main()
{
    vector<vector<int>> myvec;
    myvec.push_back(vector<int>{2});
    myvec.push_back(vector<int>{3,4});
    myvec.push_back(vector<int>{6,5,7});
    myvec.push_back(vector<int>{4,1,8,3});

    cout<<minimumTotal(myvec)<<endl;
    return 0;
}









