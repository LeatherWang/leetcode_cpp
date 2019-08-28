
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <math.h>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define MaxSize 100

// 边节点
struct ArcNode{
    int adjvex;  //有向边另一节点的序号
    int weight;  //边的权重
    ArcNode *nextArc;
};

//顶点
struct VertexNode{
    int data;      //顶点信息
    ArcNode *odegree; //出边表的表头指针
    ArcNode *idegree; //入边表的表头指针，为了方便记忆，这里的入是指相对与当前顶点是入，谁能入，只有idegree能够入进来
};

typedef LGraph * ptrToLGraph;
struct LGraph{
    VertexNode vertexs[MaxSize];
    int vexNum;
    int arcNum;
};

typedef ptrToLGraph pLGraph; //定义一个指针类型的，作为函数参数传递比较方便

LGraph lg;
//创建邻接表
void createGraph(){
    int v1,v2;    //有向边的起点和终点
    ArcNode *p1;  //边结点
    //初始化
    for(int i = 0;i < lg.verNum ; i++ ){
        lg.vertexs[i].odegree = lg.vertexs[i].idegree = NULL;
    }
    //构造出边表,入边表，使用链表的头插法
    for(int i =0 ;i < lg.arcNum ; i ++ ){
        scanf("%d%d",&v1,&v2);
        v1--,v2--;      //注意下标
        p1 = new ArcNode;
        p1->adjvex = v2;
        p1->nextArc = lg.vertexs[v1].odegree; //v1->v2，出度
        lg.vertexs[v1].odegree = p1;

        p1 = new ArcNode;
        p1->adjvex = v1;
        p1->nextArc = lg.vertexs[v2].idegree; //v1->v2，入度
        lg.vertexs[v2].idegree = p1;
    }
}

//删除邻接表，释放节点空间
void deleteGraph(){
    int i ;
    ArcNode *p1;
    for(i =0 ;i < lg.verNum ; i++){
        p1 = lg.vertexs[i].odegree;
        //释放第i个顶点的出边表的结点信息
        while(p1 != NULL){
            lg.vertexs[i].odegree = p1->nextArc;
            delete p1;
            p1 = lg.vertexs[i].odegree;
        }
        p1 = lg.vertexs[i].idegree;
        //释放第i个顶点的入边表的结点信息
        while(p1 != NULL){
            lg.vertexs[i].idegree = p1->nextArc;
            delete p1;
            p1 = lg.vertexs[i].idegree;
        }
    }
}

int main(int argc, char *argv[]) {
    int i ;
    ArcNode *p;
    int od,id;  //有向边的出度，入度

    scanf("%d%d",&lg.verNum,&lg.arcNum);   //输入顶点的数目，边结点的数目
    createGraph();
    //出度
    for(i =0 ;i< lg.verNum;i++){
        od = 0;
        p = lg.vertexs[i].odegree;
        while(p != NULL){
            od ++;
            p = p->nextArc;
        }
        if(i == 0){
            printf("%d",od);
        }else{
            printf(" %d",od);
        }
    }

    printf("\n");  //换行

    //入度
    for(i =0 ;i< lg.verNum;i++){
        id = 0;
        p = lg.vertexs[i].idegree;
        while(p != NULL){
            id ++;
            p = p->nextArc;
        }
        if(i == 0){
            printf("%d",id);
        }else{
            printf(" %d",id);
        }
    }
    deleteGraph();    //释放邻接表的存储空间
    return 0;
}










