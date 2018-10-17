/***********************

Important to watch for infinite loops and referencing NULL nodes with problems like these.

O(n) time
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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
                
        ListNode* next = head->next;
        head->next = NULL;
        
        while (next != NULL) {
            ListNode* temp = next->next;
            next->next = head;            
            head = next;
            next = temp;
        }
        
        return head;        
    }
};