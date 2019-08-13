
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
bool hasCycle(ListNode *head)
{
    ListNode *curNode = head;
    for(;curNode;)
    {
        if(curNode->next == head) return true;
        ListNode * tmp = curNode;
        curNode = curNode->next;
        tmp->next = head;
    }
    return false;
}
int main()
{

    return 0;
}









