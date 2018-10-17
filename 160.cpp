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
    pair<int,int> getLengths(ListNode* headA, ListNode* headB) {
        int lengthA = 1;
        int lengthB = 1;
        while (headA->next) {            
            headA = headA->next;
            lengthA++;
        }
        while (headB->next) {
            headB = headB->next;
            lengthB++;            
        }
        if (headA != headB) return make_pair(-1, -1);
        else return make_pair(lengthA, lengthB);
    }
    
    ListNode* getIntersect(ListNode* longer, ListNode* shorter, int difference) {
        while (difference) {
            longer = longer->next;
            difference--;
        }
        while (longer != shorter) {
            longer = longer->next;
            shorter = shorter->next;
        }
        return longer;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        pair<int,int> lengths = getLengths(headA, headB);
        if (lengths.first == -1) return NULL;
        
        if (lengths.first >= lengths.second) return getIntersect(headA, headB, lengths.first - lengths.second);
        else return getIntersect(headB, headA, lengths.second - lengths.first);
    }
};