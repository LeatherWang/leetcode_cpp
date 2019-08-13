
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

ListNode* reverseKGroup(ListNode* head, int k)
{
    if(k <= 1) return head;
    ListNode *dummyList = new ListNode(0);
    dummyList->next = head;
    ListNode * curP = head, *preP = dummyList;

    int t = 1;
    while(curP != NULL)
    {
        if(t%k == 0) //! 寻到k个，即表示一组
        {
            ListNode * latP = curP->next;
            ListNode * lpreP = preP->next; //k个数中的第一个，在循环过程中不改变
            ListNode * lcurP = lpreP->next;
            while(lcurP != latP)
            {
                lpreP->next = lcurP->next; //! 每一次与新来的一个交换，而不是两个一交换
                lcurP->next = preP->next; //! @attention nice
                preP->next = lcurP;
                lcurP = lpreP->next;
                cout<<lcurP->val<<endl;
            }
            preP = lpreP;
            curP = preP->next;
        }
        else
            curP = curP->next;
        t++;
    }

    return dummyList->next;
}

// 给定这个链表：1->2->3->4->5
// 当 k = 3 时，应当返回: 3->2->1->4->5
int main()
{
    int num1=87654321;
    ListNode *dummyList = new ListNode(0);
    ListNode *p = dummyList;
    for(; num1>0; )
    {
        int remainder = num1%10;
        num1 /=10;

        p->next = new ListNode(remainder);
        p = p->next;
    }
    for(ListNode *startP = dummyList->next;startP!=NULL;)
    {
        cout<<startP->val;
        startP = startP->next;
    }
    cout<<endl;
    ListNode * afterList = reverseKGroup(dummyList->next, 3);

    for(ListNode *startP = afterList;startP!=NULL;)
    {
        cout<<startP->val;
        startP = startP->next;
    }
    cout<<endl;
    return 0;
}









