
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

ListNode* removeNthFromEnd_myself(ListNode* head, int n)
{
    if(!head)
    {
        return static_cast<ListNode*>(NULL);
    }

    int listSize = 0;
    ListNode *curListNode = head;
    for(;curListNode != NULL;)
    {
        listSize++;
        curListNode = curListNode->next;
    }

    int forwardIndex = listSize - n +1;
    curListNode = head;
    ListNode *lastListNode = curListNode, *returnNode;
    if(forwardIndex != 1)
    {
        for(int index=0; curListNode != NULL; )
        {
            index ++;
            if(index == forwardIndex)
            {
                cout<<listSize<<" "<<forwardIndex<<" "<<index<<endl;
                lastListNode->next = curListNode->next;
                delete curListNode;
                returnNode = head;
                break;
            }
            lastListNode = curListNode;
            curListNode = curListNode->next;
        }
    }
    else
    {
        returnNode = head->next;
        delete head;
    }

    return returnNode;
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    int length  = 0;
    ListNode *first = head;
    while (first != null) {
        length++;
        first = first->next;
    }
    length -= n;
    first = dummy;
    while (length > 0) {  //! 注意这里，直接使用Index自减，而不是另外加一个变量，加到与其相等
        length--;
        first = first->next;
    }
    first->next = first->next->next; //对啊，索引到要删除节点的前一个就行啊!!
    return dummy->next;
}

//1->2->3->4->5, 和 n = 2.
//当删除了倒数第二个节点后，链表变为 1->2->3->5
int main()
{
    int num1=12345;
    ListNode *mylist = static_cast<ListNode*>(NULL);
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
    for(ListNode *curP = mylist;curP!=NULL;)
    {
        cout<<curP->val;
        curP = curP->next;
    }
    cout<<endl;

    ListNode * afterList = removeNthFromEnd(mylist, 5);

    for(ListNode *curP = afterList;curP!=NULL;)
    {
        cout<<curP->val;
        curP = curP->next;
    }
    cout<<endl;
    return 0;
}









