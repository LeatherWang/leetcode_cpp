
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

int addNum(ListNode* l1, ListNode* l2, int lengthL1, int lengthL2)
{
    if(lengthL1 <= 0 || lengthL2 <= 0)
        return 0;
    if(lengthL1>lengthL2)
    {
        l1->val += addNum(l1->next, l2, lengthL1-1, lengthL2);
        if(l1->val>9)
        {
            l1->val -=10;
            return 1;
        }
        else
            return 0;
    }
    else if(lengthL1 == lengthL2)
    {
        l1->val += l2->val;
        l1->val += addNum(l1->next, l2->next, lengthL1-1, lengthL2-1);
        if(l1->val>9)
        {
            l1->val -=10;
            return 1;
        }
        else
            return 0;
    }
    else cout<<"error!!"<<endl;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    if(!l1)
        return l2;
    else if(!l2)
        return l1;
    ListNode *head=NULL;
    int lengthL1=0, lengthL2=0;
    ListNode *tmpNode = l1;
    while(tmpNode)
    {
        lengthL1++;
        tmpNode = tmpNode->next;
    }
    tmpNode = l2;
    while(tmpNode)
    {
        lengthL2++;
        tmpNode = tmpNode->next;
    }

    if(lengthL1 < lengthL2)
        swap(lengthL1, lengthL2), swap(l1, l2);
    if(addNum(l1, l2, lengthL1, lengthL2))
    {
        head = new ListNode(1);
        head->next = l1;
        l1 = head;
    }
    return l1;
}

int main()
{

    return 0;
}









