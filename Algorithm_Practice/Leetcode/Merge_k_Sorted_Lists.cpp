#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

ListNode* mergeTwoSortedArray(ListNode* l1, ListNode* l2) {
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    while(temp1 != NULL || temp2 != NULL){
        if(temp1 == NULL){
            curr->next = temp2;
            break;
        }
        else if(temp2 == NULL){
            curr->next = temp1;
            break;
        }
        
        if(temp1->val <= temp2->val){
            curr->next = temp1;
            temp1 = temp1->next;
            curr = curr->next;
        }
        else{
            curr->next = temp2;
            temp2 = temp2->next;
            curr = curr->next;
        }
    }
    return head->next;
}

ListNode* merge(vector<ListNode*>& lists) {
    if(lists.empty())
        return NULL;
    int size = lists.size();
    if(size == 1)
        return lists[0];
    else{
        vector<ListNode*> f_half (lists.begin(), lists.begin() + size / 2);
        vector<ListNode*> s_half (lists.begin() + size / 2, lists.end());
        return mergeTwoSortedArray(merge(f_half), merge(s_half));
    }
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty())
        return NULL;
    return merge(lists);
}

int main(int argc, char const *argv[])
{
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
这里主要的地方是我把merge K list分成了merge前一半的list和merge后一半的list，然后再合并起来。
据说也能使用Heap排序，这个之后再进行研究。
 */

