
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

class MyLinkedList {
public:
    ListNode *myListDummy;
    /** Initialize your data structure here. */
    MyLinkedList() {
        myListDummy = new ListNode(0);
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode *tmpNode = myListDummy->next;
        for(;tmpNode && index>0;index--)
            tmpNode = tmpNode->next;
        if(tmpNode)
            return tmpNode->val;
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *tmp = myListDummy->next;
        myListDummy->next = new ListNode(val);
        myListDummy->next->next = tmp;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *tmpNode = myListDummy;
        for(;tmpNode->next;)
            tmpNode = tmpNode->next;
        tmpNode->next = new ListNode(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode *tmpNode = myListDummy;
        for(;tmpNode->next && index>0;index--)
            tmpNode = tmpNode->next;
        if(tmpNode->next || index == 0) //插到中间和末尾，超出不插入
        {
            ListNode *tempP = tmpNode->next;
            tmpNode->next = new ListNode(val);
            tmpNode->next->next = tempP;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode *tmpNode = myListDummy;
        for(;tmpNode->next && index>0;index--)
            tmpNode = tmpNode->next;
        if(tmpNode->next)
        {
            tmpNode->next = tmpNode->next->next;
        }
    }
};
int main()
{
    MyLinkedList *obj = new MyLinkedList();
    cout<<obj->get(1)<<endl;
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    obj->deleteAtIndex(1);
    cout<<obj->get(1)<<endl;
    return 0;
}









