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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* current = head;
        ListNode* next = current->next;
        
        while (next) {
            if (current->val == next->val) {                
                current->next = next->next;
                next = next->next;
            }
            else {
                current = next;
                next = next->next;
            }
        }
        return head;
    }
};