
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

ListNode* middleNode(ListNode* head)
{
    ListNode * mid = head;
    ListNode *tail = head;
    if(mid->next==NULL)
        return mid;
    for(;tail!=NULL && tail->next!=NULL;)
    {
        mid = mid->next;
        tail = tail->next->next;
    }
    return mid;
}
int main()
{

    return 0;
}









