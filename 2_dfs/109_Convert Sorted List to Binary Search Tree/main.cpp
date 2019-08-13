
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
#include <set>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

TreeNode* dfs(ListNode* head, ListNode* tail) //!@attention 注意理解这里的tail，不是一直都是NULL，见40行
{
    if(head == tail) return NULL;
    if(head->next==tail) //剩下最后两个的时候，要特别处理一下
    {
        return new TreeNode(head->val);
    }

    ListNode *mid=head, *temp=head;
    for(;temp!=tail && temp->next!=tail;)
    {
        mid = mid->next;
        temp = temp->next->next;
    }
    TreeNode *bt = new TreeNode(mid->val);
    bt->left = dfs(head, mid); //tail 不再是NULL了
    bt->right = dfs(mid->next, tail);
    return bt;
}
TreeNode* sortedListToBST(ListNode* head)
{
    return dfs(head, NULL);
}
int main()
{
    return 0;
}









