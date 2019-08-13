
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

ListNode* mergeTwoLists_myself(ListNode* l1, ListNode* l2)
{
    ListNode * dummyList = new ListNode(0);
    ListNode *curL1 = l1, *curL2 = l2, *curMergeL = dummyList;
    for(;curL1!=NULL && curL2!=NULL;)
    {
        if(curL1->val < curL2->val)
        {
            cout<<"curL1->val: "<<curL1->val<<endl;
            curMergeL->next = new ListNode(curL1->val);
            curMergeL = curMergeL->next;
            curL1 = curL1->next;
        }
        else if(curL1->val > curL2->val)
        {
            cout<<"curL2->val: "<<curL2->val<<endl;
            curMergeL->next = new ListNode(curL2->val);
            curMergeL = curMergeL->next;
            curL2 = curL2->next;
        }
        else
        {
            cout<<"=curL1->val: "<<curL1->val<<endl;
            curMergeL->next = new ListNode(curL1->val);
            curMergeL = curMergeL->next;
            curL1 = curL1->next;
            cout<<"=curL2->val: "<<curL2->val<<endl;
            curMergeL->next = new ListNode(curL2->val);
            curMergeL = curMergeL->next;
            curL2 = curL2->next;
        }
        cout<<"loop"<<endl;
    }

    for(;curL1 !=NULL;)
    {
        curMergeL->next = new ListNode(curL1->val);
        curMergeL = curMergeL->next;
        curL1 = curL1->next;
    }

    for(;curL2 !=NULL;)
    {
        curMergeL->next = new ListNode(curL2->val);
        curMergeL = curMergeL->next;
        curL2 = curL2->next;
    }

    return dummyList->next;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if(!l1)return l2;
    if(!l2)return l1;
    ListNode * head;
    if(l1->val<= l2->val){
        head = l1;
        l1 =l1->next;
    }
    else{
        head = l2;
        l2 = l2->next;
    }
    ListNode *p = head;
    while(l1 && l2){
        if(l1->val <= l2->val){
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        }
        else{
            p->next = l2;
            l2 = l2->next;
            p= p->next;
        }
    }
    if(l1)p->next = l1; /** @attention 链表的魅力所在，把地址给它就行了*/
    else p->next = l2;
    return head;
}

int main()
{
    int num1=54321, num2=431;
    ListNode *mylist = static_cast<ListNode*>(NULL), *mylist2 = static_cast<ListNode*>(NULL);
    ListNode *curListNode = static_cast<ListNode*>(NULL);
    for(; num1>0; )
    {
        int remainder = num1%10;
        num1 /=10;

        if(mylist)
        {
            curListNode->next = new ListNode(remainder);
            curListNode = curListNode->next;
        }
        else
        {
            mylist = new ListNode(remainder);
            curListNode = mylist;
        }
    }

    for(; num2>0; )
    {
        int remainder = num2%10;
        num2 /=10;

        if(mylist2)
        {
            curListNode->next = new ListNode(remainder);
            curListNode = curListNode->next;
        }
        else
        {
            mylist2 = new ListNode(remainder);
            curListNode = mylist2;
        }
    }

    ListNode * afterList = mergeTwoLists(mylist, mylist2);

    for(ListNode *curP = afterList;curP!=NULL;)
    {
        cout<<curP->val;
        curP = curP->next;
    }
    cout<<endl;
    return 0;
}









