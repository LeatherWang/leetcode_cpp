
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

ListNode* deleteDuplicates(ListNode* head)
{
    if(!head)
        return NULL;
    ListNode *lastNode = head;
    ListNode *curNode = head->next;
    for(;curNode != NULL;)
    {
        if(lastNode->val == curNode->val)
        {
            lastNode->next = curNode->next;
        }
        else
        {
            lastNode = curNode;
        }
        curNode = curNode->next;
    }
    return head;
}

int main()
{

    return 0;
}









