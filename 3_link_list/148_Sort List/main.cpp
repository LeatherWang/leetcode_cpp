
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

ListNode* sortList(ListNode* head)
{
    if(!head)
        return head;
    vector<pair<int, ListNode*>> myvec;
    ListNode *tmpNode = head;
    for(;tmpNode;)
    {
        myvec.push_back(make_pair(tmpNode->val, tmpNode));
        tmpNode = tmpNode->next;
    }
    sort(myvec.begin(), myvec.end(),
         [](const pair<int, ListNode*> &a, const pair<int, ListNode*> &b){return a.first<b.first;});
    for(int i=1; i<myvec.size(); i++)
    {
        myvec[i-1].second->next = myvec[i].second;
    }
    myvec[myvec.size()-1].second->next = NULL;
    return myvec[0].second;
}
int main()
{

    return 0;
}









