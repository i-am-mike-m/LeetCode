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
        ListNode* next = head->next;
        head->next = NULL;
        
        while(next) {
            ListNode* temp = next->next;
            next->next = head;
            head = next;
            next = temp;
        }
        
        return head;        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1); 
        l2 = reverseList(l2);
        
        ListNode* head = NULL;
        ListNode* current = NULL;
        int carry = 0;
        while (l1 || l2) {
            if (head == NULL) {
                head = new ListNode(0);
                current = head;
            }
            else {
                current->next = new ListNode(0);
                current = current->next;
            }
            if (l1) {
                current->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                current->val += l2->val;
                l2 = l2->next;
            }
            if (carry) {
                current->val++;
                carry--;
            }
            if (current->val >= 10) {
                current->val -= 10;
                carry++;
            }
        }
        if (carry) {
            current->next = new ListNode(1);
        }
        head = reverseList(head);
        return head;
    }
};