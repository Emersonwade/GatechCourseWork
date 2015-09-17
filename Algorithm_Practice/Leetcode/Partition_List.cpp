#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

针对于这一题的指针操作实际上非常烦，讲究细节。例如这里的head包含了val值，所以我设置了一个新的head指向这个head。
同时特别需要注意的是
ListNode * c = myHead;
ListNode * sp = myHead;
这样设置了两个指针都指向同一个位置时，是需要额外小心。当修改了其中一个，就会影响到另外的一个。同时建议
ListNode *oNode = c->next;
ListNode *nNode = c->next->next;
ListNode *spNext = sp->next;
这样的取现在指针的值next之类的变量，优先取好防止之后的修改。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int main(int argc, char const *argv[])
{
    return 0;
}

ListNode* partition(ListNode* head, int x) {
    ListNode *myHead = new ListNode(0);
    myHead->next = head;
    
    ListNode * c = myHead;
    ListNode * sp = myHead;
    
    if(c->next == NULL)
        return NULL;
    while(c != NULL && c->next != NULL){
        if((c->next)->val < x){
            ListNode *oNode = c->next;
            ListNode *nNode = c->next->next;
            ListNode *spNext = sp->next;
           
            c->next = nNode;
            
            sp->next = oNode;
            if(spNext == oNode){
                c = c->next;
                oNode->next = nNode;
            }
            else
                oNode->next = spNext;
            sp = sp->next;
        }
        else
          c = c->next;
    }
    return myHead->next;
}
/*

为了避免我使用的两个指针指向同一个地址的问题，以下解法更好。开两个list分别存放小的和大的。
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0), right(0);
        ListNode *l = &left, *r = &right;

        while(head){
            ListNode* & ref = head->val < x ? l : r;
            ref->next = head;
            ref = ref->next;

            head = head->next;
        }
        l->next = right.next;
        r->next = NULL;
        return left.next;
    }
};
 */