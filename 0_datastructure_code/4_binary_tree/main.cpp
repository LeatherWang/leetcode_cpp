#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
#define rNotUsingReocurrence

typedef int ElementType;

//存储结构
typedef struct TreeNode* BinTree;
typedef BinTree Position;
struct TreeNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
#ifndef NotUsingReocurrence
    bool firstVisitFlag;
#endif
};


// 前序遍历
void PreOrderTraversal( BinTree BT )
{
#ifdef NotUsingReocurrence
    if(BT)
    {
        cout<<BT->Data<<endl;
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
#else  //!@attention 使用递归
    BinTree T=BT;
    stack<BinTree> S;
    while( T || !S.empty() ){
        while(T){
            cout<<T->Data<<" "; //第一次到栈顶的时候，就打印出来
            S.push(T);
            T = T->Left;
        }
        if(!S.empty()){
            T = S.top();
            S.pop();
            T = T->Right;
        }
    }
    cout<<endl;
#endif
}

// 中序遍历
void InOrderTraversal( BinTree BT )
{
#ifdef NotUsingReocurrence
    if( BT ) {
        InOrderTraversal( BT->Left );
        cout<<BT->Data<<endl;
        InOrderTraversal( BT->Right );
    }
#else  //!@attention 使用递归
    BinTree T=BT;
    stack<BinTree> S;
    while( T || !S.empty() ){
        while(T){
            S.push(T);
            T = T->Left;
        }
        if(!S.empty()){
            T = S.top();
            S.pop();
            printf("%5d", T->Data); //第二次到达栈顶的打印出来
            T = T->Right;
        }
    }
#endif
}

// 后序遍历
void PostOrderTraversal( BinTree BT )
{
#ifdef NotUsingReocurrence
    if(BT) {
        PostOrderTraversal( BT->Left );
        PostOrderTraversal( BT->Right);
        cout<<BT->Data<<endl;
    }
#else  //!@attention 使用递归
    BinTree T=BT;
    stack<BinTree> S;
    while( T || !S.empty() ){
        while(T){
            S.push(T);
            T->firstVisitFlag = true;
            T = T->Left;
        }
        if(!S.empty()){
	    T = S.top();
        T = T->Right;
            if(T->firstVisitFlag)
            {
                T->firstVisitFlag = false; //
            }
            else
            {
                printf("%5d", T->Data); //第三次到达栈顶的打印出来
                S.pop();
                T = nullptr;
            }

        }
    }
#endif
}

// 层序遍历
void LevelOrderTraversal( BinTree BT )
{
    if(!BT) return;
    queue<BinTree> myqueue;
    myqueue.push(BT);
    while(!myqueue.empty()) {
        BinTree tempBT = myqueue.front();
        myqueue.pop();
        cout<<tempBT->Data<<" "<<ends;
        if(tempBT->Left)
            myqueue.push(tempBT->Left);
        if(tempBT->Right)
            myqueue.push(tempBT->Right);
    }
    cout<<endl;
    return;
}

// 输出二叉树中的叶子结点
// 使用前序、中序、后序都可
void PreOrderPrintLeaves( BinTree BT )
{
    if( BT ) {
        if ( !BT->Left && !BT->Right ) //在二叉树的遍历算法中增加检测结点的“左右子树是否都为空”
            cout<<BT->Data<<" "<<ends;
        PreOrderPrintLeaves ( BT->Left );
        PreOrderPrintLeaves ( BT->Right );
    }
}

// 求二叉树的高度
// 使用的是后序遍历
int PostOrderGetHeight( BinTree BT )
{
    int HL, HR, MaxH;
    if( BT ) {
        HL = PostOrderGetHeight(BT->Left);
        HR = PostOrderGetHeight(BT->Right);
        MaxH = max(HL,HR);
        return ( MaxH + 1 );
    }
    else return 0;
}

// 先序和中序遍历序列来确定一棵二叉树
/** @todo */

void createBinaryTree(BinTree *BT, int myarr[], int &k)
{
    int temp = myarr[k];
    if(temp == 0)
    {
        *BT = NULL;
    }
    else
    {
        *BT = (BinTree)malloc(sizeof(TreeNode));
        (*BT)->Data = temp;
        createBinaryTree(&(*BT)->Left, myarr, ++k); //!@attention 注意别忘了引用符号
        createBinaryTree(&(*BT)->Right, myarr, ++k);//!@attention (*BT)两边的括号不能少
    }
}

// 插入二叉排序树--leatherwang实现
bool InsertNode(BinTree *BT, ElementType x)
{
    if(!(*BT))
    {
        cout<<x<<endl;
        *BT = (BinTree)malloc(sizeof(TreeNode)); //!@attention (BinTree) 两边的括号不能少
        (*BT)->Data = x;
        (*BT)->Left = (*BT)->Right = NULL;
        return true;
    }
    else
    {
        if(x == (*BT)->Data)
            return false;
        else if(x < (*BT)->Data)
        {
            if(InsertNode(&((*BT)->Left), x))
                return true;
        }
        else if(x > (*BT)->Data)
        {
            if(InsertNode(&((*BT)->Right), x))
                return true;
        }
    }
    return false;
}

// 插入二叉排序树--陈越老师实现
//! @attention 注意这里是怎么解决BST为空指针的问题的
BinTree Insert(BinTree BST, ElementType X )
{
    if( !BST )
    {
        BST = (BinTree)malloc(sizeof(struct TreeNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else
    {
        if( X < BST->Data )
            BST->Left = Insert(BST->Left, X);
        else if( X > BST->Data )
            BST->Right = Insert(BST->Right, X);
    }
    return BST;
}

Position Find(BinTree BST, ElementType X)
{
    if( !BST ) return NULL; /*查找失败*/
    if( X > BST->Data )
        return Find(BST->Right, X); /*在右子树中继续查找*/
    else if( X < BST->Data )
        return Find(BST->Left, X); /*在左子树中继续查找*/
    else /* X == BST->Data */
        return BST; /*查找成功， 返回结点的找到结点的地址*/
}

Position IterFind(BinTree BST, ElementType X)
{
    while( BST ) {
        if( X > BST->Data )
            BST = BST->Right; /*向右子树中移动， 继续查找*/
        else if( X < BST->Data )
            BST = BST->Left; /*向左子树中移动， 继续查找*/
        else /* X == BST->Data */
            return BST; /*查找成功， 返回结点的找到结点的地址*/
    }
    return NULL; /*查找失败*/
}

// 查找最小元素的递归函数
Position FindMin( BinTree BST )
{
    if( !BST ) return NULL; /*空的二叉搜索树，返回NULL*/
    if( !BST->Left )
        return BST; /*找到最左叶结点并返回*/
    return FindMin( BST->Left ); /*沿左分支继续查找*/
}

// 查找最大元素的迭代函数
Position FindMax( BinTree BST )
{
    if(BST )
        while( BST->Right ) BST = BST->Right;
    return BST;
}

//! 注意这个返回值是BinTree，`BST->Left = Delete( X, BST->Left);`函数可能返回新指针给BST->Left
BinTree Delete( ElementType X, BinTree BST )
{
    Position Tmp;
    if( !BST ) printf("要删除的元素未找到");
    else if( X < BST->Data )
        BST->Left = Delete( X, BST->Left);
    else if( X > BST->Data )
        BST->Right = Delete( X, BST->Right);
    else
    {
        if( BST->Left && BST->Right ) //被删除结点有两个子结点
        {
            Tmp = FindMin( BST->Right );
            BST->Data = Tmp->Data;
            BST->Right = Delete( BST->Data, BST->Right);
        }
        else //被删除结点有一个或无子结点
        {
            Tmp = BST;
            if( !BST->Left ) //有右孩子或无子结点
                BST = BST->Right;
            else if( !BST->Right ) //有左孩子或无子结点
                BST = BST->Left;
            free( Tmp );
        }
    }
    return BST;
}

int main()
{

    int myarr[]={5,1,2,4,6,3,7,8};
    int k;
    k=sizeof(myarr)/sizeof(myarr[0]);
    cout<<"建立排序二叉树顺序: "<<endl;
    BinTree myBT1=NULL;
    for(int i=0; i<k; i++)
    {
        //InsertNode(&myBT1, myarr[i]);
        myBT1 = Insert(myBT1, myarr[i]);
    }
    cout<<"递归寻找，找到数字8了吗? "<<Find(myBT1, 8)->Data<<endl;
    cout<<"非递归寻找，找到数字8了吗? "<<IterFind(myBT1, 8)->Data<<endl;

    int myarr2[]={1,2,3,0,0,4,0,0,5,6,0,0,7,0,0};
    BinTree myBT;
    k=0;
    cout<<"建立普通二叉树: "<<endl;
    createBinaryTree(&myBT, myarr2, k);
    cout<<"前序遍历:"<<endl;
    PostOrderTraversal(myBT);
    cout<<"层序遍历:"<<endl;
    LevelOrderTraversal(myBT);
    cout<<"打印叶子:"<<endl;
    PreOrderPrintLeaves(myBT);
    cout<<endl;
    cout<<"求二叉树的高度:"<<endl;
    cout<<PostOrderGetHeight(myBT)<<endl;

    return 0;
}
