#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Sort a linked list using insertion sort.
 */

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

void insertNode(ListNode** head, ListNode* insertNode, ListNode* preNode){
    if((*head)->val > insertNode->val){
        preNode->next = insertNode->next;
        insertNode->next = *head;
        *head = insertNode;
        return;
    }
    
    ListNode* temp = *head;
    while(temp->next != NULL && temp->next->val < insertNode->val){
        temp = temp->next;
    }
    preNode->next = insertNode->next;
    insertNode->next = temp->next;
    temp->next = insertNode;
}

ListNode* insertionSortList(ListNode* head) {
    if(head == NULL)
        return NULL;
    ListNode* temp = head;
    while(temp->next != NULL){
        if(temp->next->val < temp->val){
            insertNode(&head, temp->next, temp);
        }
        else
            temp = temp->next;
    }
    return head;
}

int main(int argc, char const *argv[])
{
    ListNode* head = new ListNode(1);
    ListNode* next_head = new ListNode(0);
    head->next = next_head;
    ListNode* temp1 = new ListNode(2);
    next_head->next = temp1;
    ListNode* temp2 = new ListNode(3);
    temp1->next = temp2;

    ListNode* n_head = insertionSortList(head);
    ListNode* i = n_head;
    while(i != NULL){
        cout << i->val << endl;
        i = i->next;
    }

    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
注意点：在对linkedlist的head进行赋值的时候，也就是对于指针进行赋值时
（修改指针本身指向的位置时），需要使用到指向指针的指针，不然会赋值失败。
        *head = insertNode;
 */

