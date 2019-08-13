
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int numTrees(int n)
{
    vector<int> res(n, 0);
    res[0]=1;
    res[1]=1;
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<= i; j++)
        {
            res[i] += res[j-1]*res[i-j];
        }
    }
    return res[n];
}

int main()
{
    TreeNode *mybt = new TreeNode(3);
    return 0;
}









