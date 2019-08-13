
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head)
{
    if(!head || !head->next || head->next->next)
        return;
    vector<ListNode*> myvec;
    ListNode *tmpNode = head;
    for(int i=0;tmpNode;i++)
    {
        myvec.push_back(tmpNode);
        tmpNode = tmpNode->next;
    }
    tmpNode = head;
    tmpNode->next = myvec.back();
    tmpNode = tmpNode->next;
    int i=1;
    int N=myvec.size()-1;
    for(; i < (N-i); i++)
    {
        tmpNode->next = myvec[i];
        tmpNode->next->next = myvec[N-i];
        tmpNode = tmpNode->next->next;
    }

    if(i == (N-i))
    {
        tmpNode->next = myvec[i];
        tmpNode->next->next = NULL;
    }
    else
    {
        tmpNode->next = NULL;
    }
}

void reorderList_1(ListNode* head)
{
    if(!head || !head->next || !head->next->next)
        return;
    ListNode *tail = head;
    ListNode *mid = head;
    for(;tail && tail->next;)
    {
        mid = mid->next;
        tail = tail->next->next;
    }

    if(tail)
        mid = mid->next;

    ListNode *curNode = mid, *tmpNode, *preNode=NULL;
    for(;curNode;)
    {
        tmpNode = curNode;
        curNode = curNode->next;
        tmpNode->next = preNode;
        preNode = tmpNode;
    }

    ListNode *left=head, *right=preNode;
    for(;right;)
    {
        tmpNode = left;
        left = left->next;
        tmpNode->next = right;
        right = right->next;
        if(right)
            tmpNode->next->next = left;
        else if(tail)
        {
            tmpNode->next->next = left;
            left->next = NULL;
        }
    }
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *tmpNode = head;
    tmpNode->next = new ListNode(2);
    tmpNode = tmpNode->next;
    tmpNode->next = new ListNode(3);
    tmpNode = tmpNode->next;
    tmpNode->next = new ListNode(4);
    tmpNode = tmpNode->next;
    tmpNode->next = new ListNode(5);
    tmpNode = tmpNode->next;
    reorderList_1(head);
    tmpNode = head;
    for(;tmpNode;)
    {
        cout<<tmpNode->val<<endl;
        tmpNode = tmpNode->next;
    }

    return 0;
}









