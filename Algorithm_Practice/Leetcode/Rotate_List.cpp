#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
            
        ListNode* i = head;
        ListNode* nHead = NULL;
        int count = 1;
        
        while(i->next != NULL){
            i = i->next;
            count ++;
        }
        
        i->next = head;
        i = head;
        k = k % count;
        
        for(int it = 0; it < count - k - 1; it ++){
            i = i->next;
        }
        nHead = i->next;
        i->next = NULL;
        
        return nHead;
    }
};

int main(int argc, char const *argv[])
{
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
这一题的关键就在于一开始我们就需要将整个链表环绕起来，再去考虑从哪里将链表断开。
Rotate的意思就是对链表进行旋转，那么首先就要将链表连接。
额外需要注意的是对于K的处理，我们使用mode操作来降低K的大小，从而加强效率。
 */

