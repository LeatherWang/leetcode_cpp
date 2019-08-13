
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int lengthA=0, lengthB=0;
    ListNode *tmpNode= headA;
    for(;tmpNode;)
    {
        lengthA++;
        tmpNode= tmpNode->next;
    }
    tmpNode= headB;
    for(;tmpNode;)
    {
        lengthB++;
        tmpNode= tmpNode->next;
    }

    while(lengthA > lengthB)
    {
        headA = headA->next;
        lengthA--;
    }

    while(lengthA < lengthB)
    {
        headB = headB->next;
        lengthB--;
    }

    for(;headA != headB && headA;)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}
int main()
{

    return 0;
}









