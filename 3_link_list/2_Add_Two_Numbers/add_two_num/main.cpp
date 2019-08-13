
#include <iostream>  // std::cout
#include <vector>    // std::vector
#include <algorithm> // std::sort
#include <math.h>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* list1, ListNode* list2)
{
    ListNode *listSum = static_cast<ListNode*>(NULL);
    ListNode *p1=list1, *p2=list2, *p3;
    int carry=0;
    for( ;(p1 != NULL) || (p2 != NULL) || carry!=0; ) //注意第三个条件(输入为5,5时)
    {
        int value1=0, value2=0;
        if(p1!=NULL)
        {
            value1 = p1->val;
            p1 = p1->next;
        }
        if(p2!=NULL)
        {
            value2 = p2->val;
            p2 = p2->next;
        }
        int sum = value1+value2+carry;
        if(listSum)
        {
            p3->next = new ListNode((sum)%10);
            p3 = p3->next;
        }
        else
        {
            listSum = new ListNode((sum)%10);
            p3 = listSum;
        }

        // 想想下面为什么错?
        // p3是指向listSum，你怎么能让她指向其它地方呢...
//        p3 = new ListNode((sum)%10);
//        p3 = p3->next;

        cout<< p3->val  <<endl;
        carry = sum/10;
    }

    ListNode *p4=listSum;
    for(;p4 != NULL;)
    {
        cout<<"p->val: "<<p4->val<<endl;
        p4 = p4->next;
    }
    cout<<endl;
    return listSum;
}

int main()
{
    // 342 + 465 = 807
    int a1=5, a2=5;

    ListNode *list1=static_cast<ListNode*>(NULL), *list2=static_cast<ListNode*>(NULL); /** @attention 对象指针地址不定*/
    ListNode *nextNode;
    for(; a1 != 0;)
    {
        int b1 = a1%10;
        a1 /= 10;
        if(list1)
        {
            ListNode *list1_next = new ListNode(b1);
            nextNode->next = list1_next;
            nextNode = list1_next;
//            cout<<list1_next->val<<endl;
        }
        else
        {
            list1 = new ListNode(b1);
            nextNode = list1;
//            cout<<list1->val<<endl;
        }
    }
    cout<<"print"<<endl;
    ListNode *p=list1;
    for(;p != NULL;)
    {
        cout<< p->val;
        p = p->next;
    }

    cout<<endl;
    for(; a2 != 0;)
    {
        int b2 = a2%10;
        a2 /= 10;
        if(list2)
        {
            ListNode *list2_next = new ListNode(b2);
            nextNode->next = list2_next;
            nextNode = list2_next;
            //cout<<nextNode->val<<endl;
        }
        else
        {
            list2 = new ListNode(b2);
            nextNode = list2;
            //cout<<nextNode->val<<endl;
        }
    }
    cout<<"print"<<endl;
    p=list2;
    for(;p != NULL;)
    {
        cout<< p->val;
        p = p->next;
    }

    cout<<endl;
    addTwoNumbers(list1, list2);


    return 0;
}
