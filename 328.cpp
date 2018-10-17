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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_start = head->next;
        
        while (odd && even) {
            odd->next = even->next;
            odd = odd->next;
            if (odd) even->next = odd->next;
            else even->next = NULL;
            even = even->next;
        }
        ListNode* find_mid = head;
        while (find_mid->next) find_mid = find_mid->next;
        find_mid->next = even_start;
        
        return head;
    }
};