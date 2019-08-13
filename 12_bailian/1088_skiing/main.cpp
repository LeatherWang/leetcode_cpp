
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include "time.h"

using namespace std;

struct NodePos{
    int i;
    int j;
    int val;
    bool operator < (const NodePos &b) const {return val < b.val;}
    NodePos(int a, int b, int c):i(a),j(b),val(c){}
};

int main()
{
    time_t start = clock();
    int rows, cols;
    cin>>rows>>cols;
    vector<vector<int>> arr(rows, vector<int>(cols, 0));
    vector<vector<int>> res(rows, vector<int>(cols, 0));
    vector<NodePos> vecNode;
    vector<pair<int, pair<int,int>>> vecPairNode;
    for(int i=0; i< rows; i++)
    {
        for(int j=0; j< cols; j++)
        {
            cin >> arr[i][j];
            //vecNode.emplace_back(i, j, arr[i][j]); //! @todo test emplace_back
            vecPairNode.push_back(make_pair(arr[i][j], make_pair(i, j)));
        }
    }
    //sort(vecNode.begin(), vecNode.end());
    auto cmp = [](const pair<int, pair<int,int>> &a, const pair<int, pair<int,int>> &b)
    {
        return a.first < b.first;
    };
    sort(vecPairNode.begin(), vecPairNode.end(), cmp);

    int resI=0;
    for(int k=0; k< vecPairNode.size(); k++)
    {
        int i = vecPairNode[k].second.first;
        int j = vecPairNode[k].second.second;
        if(i-1 >= 0 && arr[i-1][j] < arr[i][j])
            res[i][j]= max(res[i][j] , res[i-1][j]);

        if(i+1 < rows && arr[i+1][j] < arr[i][j])
            res[i][j] = max(res[i][j] , res[i+1][j]);

        if(j-1 >= 0 && arr[i][j-1] < arr[i][j])
            res[i][j] = max(res[i][j] , res[i][j-1]);

        if(j+1 < cols && arr[i][j+1] < arr[i][j])
            res[i][j] = max(res[i][j] , res[i][j+1]);

        res[i][j]++;
        resI = max(res[i][j], resI);
    }
    cout<<resI<<endl;
    cout<<((double)(clock()-start))/CLOCKS_PER_SEC<<endl;
    return 0;
}









