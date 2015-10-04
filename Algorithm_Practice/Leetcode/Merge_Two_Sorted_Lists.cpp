#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
 */
struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* n_l = head;
    while(l1 != NULL || l2 != NULL){
        if(l1 == NULL){
            n_l->next = l2;
            l2 = l2->next;
            n_l = n_l->next;
            continue;
        }
        else if(l2 == NULL){
            n_l->next = l1;
            l1 = l1->next;
            n_l = n_l->next;
            continue;
        }

        if(l1->val > l2->val){
            n_l->next = l2;
            l2 = l2->next;
            n_l = n_l->next;
            continue;
        }
        else if(l1->val <= l2->val){
            n_l->next = l1;
            l1 = l1->next;
            n_l = n_l->next;
            continue;
        }
    }
    return head->next;
}

int main(int argc, char const *argv[])
{
    /*
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(1);
    l1->next = l2;
    ListNode* l3 = new ListNode(8);
    l2->next = l3;
    ListNode* l4 = new ListNode(10);
    l3->next = l4;
    */
    ListNode* l1 = NULL;
    ListNode* l5 = new ListNode(3);
    ListNode* l6 = new ListNode(4);
    l5->next = l6;
    ListNode* l7 = new ListNode(15);
    l6->next = l7;

    ListNode* head = mergeTwoLists(l1,l5);
    while(head != NULL){
        cout << head->val << endl;
        head = head->next;
    }
    //system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
这一题需要额外注意几个点，首先就是对于一个linked list如果为空了，那么检测另外一个是否为空，然后将另外一个整体链接到新的list中去。
这个边界条件一定要注意，否则的话会过不了，然后另外一点就针对于指针的操作，不可以有
**************************************
ListNode* n_l = NULL;
ListNode* head = n_l;
然后再对n_1进行赋值，因为一点这样子完成之后，head就指向了空地址。就会导致错误，所以要给n_l分配好一个固定地址。
**************************************

class Solution {
public:
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //return solution1(l1, l2);       //iterative
    //return solution2(l1, l2);       //recursive
    return solution3(l1, l2);       //recursive
}
private:
ListNode *solution1(ListNode *l1, ListNode *l2){
    if(!l1 && !l2) return NULL;
    if(!l1 || !l2) return !l1 ? l2 : l1;
    ListNode *newHead, *cur;
    newHead = l1->val > l2->val ? l2 : l1;
    cur = newHead;
    l1->val > l2->val ? l2=l2->next : l1=l1->next;
    while(l1 && l2){
        cur->next = l1->val > l2->val ? l2 : l1;
        l1->val > l2->val ? l2=l2->next : l1=l1->next;
        cur = cur->next;
    }
    cur->next = l1 == NULL ? l2 : l1;
    return newHead;
}
ListNode *solution2(ListNode *l1, ListNode *l2){
    if(!l1 && !l2) return NULL;
    if(!l1 || !l2) return !l1 ? l2 : l1;
    ListNode *node;
    if(l1->val < l2->val){
        node = l1;
        node->next = solution2(l1->next, l2);
    }else{
        node = l2;
        node->next = solution2(l1, l2->next);
    }
    return node;
}
ListNode *solution3(ListNode *l1, ListNode *l2){
    if(!l1 && !l2) return NULL;
    if(!l1 || !l2) return !l1 ? l2 : l1;
    ListNode *node = l1->val < l2->val ? l1 : l2;
    node->next = solution3(l1->val < l2->val ? l1->next : l1, l1->val < l2->val ? l2 : l2->next);
    return node;
}
};
 */

