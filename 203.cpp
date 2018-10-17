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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        dummy->next = head;
        while (current->next) {
            if (current->next->val == val) {
                current->next = current->next->next;
            }
            else current = current->next;
        }
        
        return dummy->next;
    }
};