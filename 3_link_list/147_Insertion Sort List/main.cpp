
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

// [-1,5,3,4,0]
ListNode* insertionSortList(ListNode* head)
{
    if(!head || !head->next)
        return head;
    ListNode *dummyNode = new ListNode(0);
    dummyNode->next = head;
    ListNode *curNode = head;
    for(;curNode->next;)
    {
        if(curNode->val < curNode->next->val)
            curNode = curNode->next;
        else //一定会往前插的情况
        {
            ListNode *tmpNode = dummyNode;
            ListNode *curTmpNode = curNode->next;
            curNode->next = curTmpNode->next;
            while(tmpNode->next->val < curTmpNode->val) //curTmpNode插到tmpNode的后面，tmpNode->next的前面
                tmpNode = tmpNode->next;
            curTmpNode->next = tmpNode->next;
            tmpNode->next = curTmpNode;
        }
    }
    return dummyNode->next;
}

int main()
{
    ListNode *head = new ListNode(-1);
    ListNode *tmpNode = head;
    tmpNode->next = new ListNode(5);
    tmpNode = tmpNode->next;
    tmpNode->next = new ListNode(3);
    tmpNode = tmpNode->next;
    tmpNode->next = new ListNode(4);
    tmpNode = tmpNode->next;
    tmpNode->next = new ListNode(0);
    tmpNode = tmpNode->next;

    insertionSortList(head);
    return 0;
}









