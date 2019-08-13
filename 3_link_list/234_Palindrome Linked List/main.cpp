
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

bool isPalindrome_1(ListNode* head)
{
    ListNode *mid = head;
    ListNode *tail = head;
    if(mid == NULL || mid->next == NULL)
        return head;
    for(;tail != NULL && tail->next != NULL;)
    {
        mid = mid->next;
        tail = tail->next->next;
    }

    if(tail) //当有奇数个元素时，后半部分少分一个，前半部分多分一个
        mid = mid->next;

    ListNode *preNode, *tmpNode, *curNode;
    curNode = mid; preNode = NULL;
    for(;curNode;)
    {
        tmpNode = curNode;
        curNode = curNode->next;
        tmpNode->next = preNode;
        preNode = tmpNode;
    }


    ListNode *left=head;
    ListNode *right = preNode; //dummy->next;
    for(;right != NULL;)
    {
        if(left->val != right->val)
            return false;
        left = left->next;
        right = right->next;
    }
    return true;
}

void dfs(const int& n, const int &k, int start, vector<vector<int>> &res, vector<int> &curVec)
{
    if(curVec.size() == k)
    {
        res.push_back(curVec);
        return;
    }
    for(int i= start; i <= n; i++)
    {
        curVec.push_back(i);
        dfs(n, k, i+1, res, curVec);
        curVec.pop_back();
    }
}
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    if(n<k)
        return res;
    vector<int> curVec;
    dfs(n, k, 1, res, curVec);
    return res;
}
int main()
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(1);
    cout<<isPalindrome(root)<<endl;
    return 0;
}









