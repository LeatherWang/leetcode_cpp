
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

ListNode* oddEvenList(ListNode* head)
{
    if(!head || !head->next)
        return head;
    ListNode *evenNode = head;
    ListNode *oddNode = head->next;
    for(;oddNode && oddNode->next;)
    {
        evenNode->next = oddNode->next;
        evenNode = evenNode->next;
        oddNode->next = evenNode->next;
        oddNode = oddNode->next;
    }
    if(oddNode)
        oddNode->next = NULL;
    evenNode->next = oddNode;
    return head;
}
int main()
{

    return 0;
}









