
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int numSquares(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    // cntPerfectSquares[i] = the least number of perfect square numbers
    // which sum to i. Since cntPerfectSquares is a static vector, if
    // cntPerfectSquares.size() > n, we have already calculated the result
    // during previous function calls and we can just return the result now.
    vector<int> cntPerfectSquares({0});

    // While cntPerfectSquares.size() <= n, we need to incrementally
    // calculate the next result until we get the result for n.
    while (cntPerfectSquares.size() <= n)
    {
        int m = cntPerfectSquares.size();
        int cntSquares = INT_MAX;
        for (int i = 1; i*i <= m; i++)
        {
            cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
        }

        cntPerfectSquares.push_back(cntSquares);
    }

    return cntPerfectSquares[n];
}

int numSquares(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    // perfectSquares contain all perfect square numbers which
    // are smaller than or equal to n.
    vector<int> perfectSquares;
    // cntPerfectSquares[i - 1] = the least number of perfect
    // square numbers which sum to i.
    vector<int> cntPerfectSquares(n);

    // Get all the perfect square numbers which are smaller than
    // or equal to n.
    for (int i = 1; i*i <= n; i++)
    {
        perfectSquares.push_back(i*i);
        cntPerfectSquares[i*i - 1] = 1;
    }

    // If n is a perfect square number, return 1 immediately.
    if (perfectSquares.back() == n)
    {
        return 1;
    }

    // Consider a graph which consists of number 0, 1,...,n as
    // its nodes. Node j is connected to node i via an edge if
    // and only if either j = i + (a perfect square number) or
    // i = j + (a perfect square number). Starting from node 0,
    // do the breadth-first search. If we reach node n at step
    // m, then the least number of perfect square numbers which
    // sum to n is m. Here since we have already obtained the
    // perfect square numbers, we have actually finished the
    // search at step 1.
    queue<int> searchQ;
    for (auto& i : perfectSquares)
    {
        searchQ.push(i);
    }

    int currCntPerfectSquares = 1;
    while (!searchQ.empty())
    {
        currCntPerfectSquares++;

        int searchQSize = searchQ.size();
        for (int i = 0; i < searchQSize; i++)
        {
            int tmp = searchQ.front();
            // Check the neighbors of node tmp which are the sum
            // of tmp and a perfect square number.
            for (auto& j : perfectSquares)
            {
                if (tmp + j == n)
                {
                    // We have reached node n.
                    return currCntPerfectSquares;
                }
                else if ((tmp + j < n) && (cntPerfectSquares[tmp + j - 1] == 0))
                {
                    // If cntPerfectSquares[tmp + j - 1] > 0, this is not
                    // the first time that we visit this node and we should
                    // skip the node (tmp + j).
                    cntPerfectSquares[tmp + j - 1] = currCntPerfectSquares;
                    searchQ.push(tmp + j);
                }
                else if (tmp + j > n)
                {
                    // We don't need to consider the nodes which are greater ]
                    // than n.
                    break;
                }
            }

            searchQ.pop();
        }
    }

    return 0;
}

int main()
{
    cout<<numSquares(12)<<endl;
    return 0;
}









