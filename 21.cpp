/***********************

Watch out for equal values and the difference between comparing values and node pointers.

O(m+n) time
O(1) space

***********************/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode* head = l1->val < l2->val ? l1 : l2;
        
        if (head == l1) l1 = l1->next;
        else l2 = l2->next;        
        ListNode* current = head;
               
        while (l1 && l2) {
            current->next = l1->val < l2->val ? l1 : l2;
            current = current->next;
            
            if (current == l1) l1 = l1->next;
            else l2 = l2->next;            
        }
        
        if (l1) current->next = l1;
        else current->next = l2;
        
        return head;
    }
};