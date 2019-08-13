
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

ListNode* reverseList(ListNode* head)
{
    if(head == NULL)
        return NULL;
    ListNode *dummy = new dummy(0);
    ListNode *tmpP = head->next;
    head->next = NULL;
    dummy->next = head;
    for(;tmpP!=NULL;)
    {
        ListNode *curP = tmpP;
        tmpP = tmpP->next;
        curP->next = dummy->next;
        dummy->next = curP;
    }
    return dummy->next;
}
int main()
{

    return 0;
}









