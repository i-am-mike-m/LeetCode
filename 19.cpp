class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {                
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* current = dummy;
        
        while (n) { current = current->next; n--; }
        while(current->next != NULL) {
            current = current->next;
            dummy = dummy->next;      
        }
        if (dummy->next == head) head = head->next;        
        else dummy->next = dummy->next->next;
        
        return head;
    }
};