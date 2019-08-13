
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

ListNode* removeElements(ListNode* head, int val)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *lastNode = dummy;
    ListNode *curNode = dummy->next;
    for(;curNode;)
    {
        if(curNode->val == val)
        {
            lastNode->next = curNode->next;
        }
        else
        {
            lastNode = lastNode->next;
        }
        curNode = curNode->next;
    }
    return dummy->next;
}
int main()
{

    return 0;
}









