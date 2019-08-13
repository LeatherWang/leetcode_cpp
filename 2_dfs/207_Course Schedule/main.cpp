
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


bool dfs(int **myarr, const int &numCourses, int index, vector<int> &visited)
{
    if(visited[index] == 1)
        return true;
    if(visited[index] == -1)
        return false;
    visited[index] = -1;
    for(int i=0; i<numCourses; i++)
    {
        if(myarr[index][i] == 1)
            if(!dfs(myarr, numCourses, i, visited))
                return false;
    }
    visited[index] = 1; //回路就是从这点出发回到这点，所以将该节点的左右邻接点全部访问过之后，就能排除这个节点构回路的可能了
    return true;
}
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
{
    // 构造邻接矩阵
    int **myarr = new int *[numCourses];
    for(int i=0; i<numCourses; i++)
    {
        myarr[i] = new int[numCourses];
        memset(myarr[i], 0, sizeof(int)*numCourses);
    }
    for(int i=0; i<prerequisites.size(); i++)
    {
        myarr[prerequisites[i].first][prerequisites[i].second] = 1;
    }
    vector<int> visited(numCourses, 0);

    for(int i=0; i< visited.size(); i++)
    {
        if(visited[i] == 0)
            if(!dfs(myarr, numCourses, i, visited))
                return false;
    }
    return true;
}

bool dfs_1(vector<vector<int>> adjList, int index, vector<int> &visited)
{
    visited[index] = -1;
    for(int i=0; i<adjList[index].size(); i++)
    {
        if(visited[adjList[index][i]] == -1)
            return false;
        else if(visited[adjList[index][i]] == 0)
        {
            if(!dfs_1(adjList, adjList[index][i], visited))
                return false;
        }
    }
    visited[index] = 1;
    return true;
}
bool canFinish_1(int numCourses, vector<pair<int, int>>& prerequisites)
{
    vector<vector<int>> adjList(numCourses); //构造邻接表
    for(int i=0; i<prerequisites.size(); i++)
    {
        adjList[prerequisites[i].first].push_back(prerequisites[i].second);
    }
    vector<int> visited(numCourses, 0);
    for(int i=0; i< visited.size(); i++)
    {
        if(visited[i] == 0)
            if(!dfs_1(adjList, i, visited))
                return false;
    }
    return true;
}

int main()
{
    vector<pair<int, int>> myvec;
    myvec.push_back(make_pair(2,0));
    myvec.push_back(make_pair(1,0));
    myvec.push_back(make_pair(3,1));
    myvec.push_back(make_pair(3,2));
    myvec.push_back(make_pair(1,3));
    cout<<canFinish_1(4, myvec)<<endl;
    //  binaryTreePaths();
    return 0;
}









