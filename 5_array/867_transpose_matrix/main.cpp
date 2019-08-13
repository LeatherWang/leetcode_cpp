
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

vector<vector<int>> transpose(vector<vector<int>>& A)
{
    if(A.size() == 1 && A[0].size() == 1)
        return A;
    vector<int> b(A.size(),0);
    vector<vector<int>> B(A[0].size(), b);
    for(int i=0; i< A.size(); i++)
    {
        for(int j=0; j< A[0].size(); j++)
        {
            B[j][i] = A[i][j];
        }
    }
    return B;
}

// haystack = "hello", needle = "ll"
int main()
{
    vector<vector<int>> myvec = {{7,2}}; //{1,2,3},{4,5,6},{7,8,9},{10,11,12}
    for(vector<int> vec:myvec)
    {
        for(int a:vec)
            cout<<a;
        cout<<endl;
    }
    vector<vector<int>> res = transpose(myvec);
    for(vector<int> vec:res)
    {
        for(int a:vec)
            cout<<a;
        cout<<endl;
    }
    return 0;
}









