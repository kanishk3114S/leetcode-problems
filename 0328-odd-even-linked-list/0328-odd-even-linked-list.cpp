/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (head == NULL || head->next == NULL) return head;
        
        ListNode* oddhead = NULL;
        ListNode* evenhead = NULL;
        ListNode* oddptr = NULL;
        ListNode* evenptr = NULL;
        ListNode* odd = head->next;
        ListNode* even = head;

        while (even != NULL && even->next != NULL) {

            even->next = NULL;
            if (evenhead == NULL) {
                evenhead = even;
                evenptr = evenhead;
            } else {
                evenptr->next = even;
                evenptr = evenptr->next;
            }
            even=odd->next;

            odd->next = NULL;
            if (oddhead == NULL) {
                oddhead = odd;
                oddptr = oddhead;
            } else {
                oddptr->next = odd;
                oddptr = oddptr->next;
            }
            if (even!=NULL) {
                odd = even->next; 
            }

        }

        if (even!=NULL) {
        evenptr->next = even;
        evenptr = evenptr->next;
        }
        evenptr->next = oddhead;
        return evenhead;

    }
};