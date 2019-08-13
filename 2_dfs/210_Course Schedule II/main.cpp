
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

struct ArcNode{
    int adjVex;
    ArcNode *nextArc;
    ArcNode(int adj):adjVex(adj),nextArc(NULL){}
};

struct VertexNode{
    int data;
    ArcNode *idegree; //入边表的表头指针，为了方便记忆，这里的入是指相对与当前顶点是入，谁能入，只有idegree能够入进来
    ArcNode *odegree;
    VertexNode():idegree(NULL),odegree(NULL){}
};

typedef struct GNode{
    int vexNum;
    int arcNum;
    VertexNode *vertexs; //动态(长度不定的)数组
} *LGraph;

// 耗时太久，看下面排名第一的算法
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{
    LGraph lg = new GNode;
    lg->vexNum = numCourses;
    lg->vertexs = new VertexNode[numCourses]; //初始化的同时，入度出度指针都置为NULL了

    for(int i=0; i<prerequisites.size(); i++)
    {
        int v1 = prerequisites[i].second; //想要学习课程0，你需要先完成课程1，我们用一个匹配来表示他们: [0,1]
        int v2 = prerequisites[i].first;

        ArcNode *oNode = new ArcNode(v2);
        oNode->nextArc = lg->vertexs[v1].odegree;
        lg->vertexs[v1].odegree = oNode; //v1->v2，出度

        ArcNode *iNode = new ArcNode(v1);
        iNode->nextArc = lg->vertexs[v2].idegree;
        lg->vertexs[v2].idegree = iNode; //v1->v2，入度
    }
    vector<int> vecIDegree(numCourses);
    queue<int> myque; //存入队列中，省得用vector遍历哪个变成0了
    for(int i=0; i<vecIDegree.size(); i++)
    {
        int num=0;
        ArcNode* p  = lg->vertexs[i].idegree;
        while(p != NULL)
        {
            p = p->nextArc;
            num++;
        }
        vecIDegree[i] = num;
        if(!vecIDegree[i]) myque.push(i); //如果vecIDegree[i]为0,说明它的入度为0,即它是开头
    }

    vector<int> res;
    for(;!myque.empty();)
    {
        int iVertex = myque.front();
        res.push_back(iVertex);
        //        cout<<iVertex<<endl;
        myque.pop();
        ArcNode* p  = lg->vertexs[iVertex].odegree;
        while(p != NULL)
        {
            if(!(--vecIDegree[p->adjVex]))
                myque.push(p->adjVex);
            p = p->nextArc;
        }
    }
    if(res.size() == numCourses) //不相等则表示图中有回路
        return res;
    else
        return vector<int>();
}

// 排名第一代码，使用了邻接表存储有向图(这个节点所在的arc的头)，存的同时更新入度
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> out;
    vector<int>cd(numCourses,0);
    vector<vector<int>> rd(numCourses);
    for(auto p:prerequisites)
    {
        auto f=p.first;
        auto s=p.second;
        cd[f]++;
        rd[s].push_back(f);
    }
    queue<int>dp;
    for(int i=0;i<numCourses;i++)
    {
        if(cd[i]==0)
        {
            out.push_back(i);
            dp.push(i);
        }
    }
    while(!dp.empty())
    {
        int len=dp.size();
        while(len--)
        {
            auto f=dp.front();
            for(int j=0;j<rd[f].size();j++)
            {
                int t=rd[f][j];
                cd[t]--;
                if(cd[t]==0){
                    out.push_back(t);
                    dp.push(t);}
            }
            dp.pop();
        }
    }
    if(accumulate(cd.begin(),cd.end(),0)!=0)
        return vector<int>();
    return out;
}
int main()
{
    vector<pair<int, int>> myvec;
    myvec.push_back(make_pair(2,0));
    myvec.push_back(make_pair(1,0));
    myvec.push_back(make_pair(3,1));
    myvec.push_back(make_pair(3,2));
    findOrder(4, myvec);
    return 0;
}









