
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

ListNode* swapPairs(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    ListNode *dummyList = new ListNode(0);
    dummyList->next = head;
    ListNode * curP = dummyList;
    for(; curP->next != NULL && curP->next->next != NULL; )
    {
        ListNode * nextP = curP->next;
        ListNode * nextGroup = curP->next->next->next;
        curP->next = curP->next->next;
        curP->next->next = nextP;
        curP = curP->next->next;
        curP->next = nextGroup;
    }
    return dummyList->next;
}

int main()
{
    int num1=54321;
    ListNode *dummyList = new ListNode(0);
    ListNode *p = dummyList;
    for(; num1>0; )
    {
        int remainder = num1%10;
        num1 /=10;

        p->next = new ListNode(remainder);
        p = p->next;
    }
    for(ListNode *curP = dummyList->next;curP!=NULL;)
    {
        cout<<curP->val;
        curP = curP->next;
    }
    cout<<endl;
    ListNode * afterList = swapPairs(dummyList->next);

    for(ListNode *curP = afterList;curP!=NULL;)
    {
        cout<<curP->val;
        curP = curP->next;
    }
    cout<<endl;
    return 0;
}









