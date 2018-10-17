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
    ListNode* reverseLinkedList(ListNode* head) {        
        if (!head) return head;
        ListNode* next = head->next;
        head->next = NULL;
        while (next) {
            ListNode* temp = next->next;
            next->next = head;
            head = next;
            next = temp;
        }
        return head;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        // Find Middle
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }      
        slow = slow->next;
        // Reverse Back Half
        slow = reverseLinkedList(slow);
        // Compare Front/Back
        while (slow) {
            if (head->val != slow->val) return false;
            else {
                head = head->next;
                slow = slow->next;
            }            
        }
        return true;
    }
};