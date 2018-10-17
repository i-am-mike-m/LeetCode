/***********************

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
    int getNodeCount(ListNode* head) {
        int count = 0;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        
        return count;
    }
    
    ListNode* middleNode(ListNode* head) {
        int numNodes = getNodeCount(head);
        
        numNodes = (numNodes / 2) + 1;
        
        while (numNodes > 1) {
            head = head->next;
            numNodes--;
        }
        
        return head;
    }
};