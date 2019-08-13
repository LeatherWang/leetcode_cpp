
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
void dfs(vector<vector<int>>& image, int sr, int sc, int& newColor, int &oldColor)
{
    if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size())
        return;
    if(image[sr][sc] == newColor || image[sr][sc] != oldColor)
        return;
    image[sr][sc] = newColor;
    dfs(image, sr+1, sc, newColor, oldColor);
    dfs(image, sr-1, sc, newColor, oldColor);
    dfs(image, sr, sc+1, newColor, oldColor);
    dfs(image, sr, sc-1, newColor, oldColor);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
{
    int oldColor = image[sr][sc];
    if(newColor == oldColor)
        return image;
    dfs(image, sr, sc, newColor, oldColor);
    return image;
}
int main()
{
    vector<vector<int>> myvec{{1,1,1},{1,1,0},{1,0,1}};
    myvec = floodFill(myvec,1,1,2);
    for(vector<int> vec:myvec)
    {
        for(int i:vec)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}









