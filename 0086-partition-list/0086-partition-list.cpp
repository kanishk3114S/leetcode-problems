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
    ListNode* partition(ListNode* head, int x) {

        if(head==NULL) return NULL;
        
        ListNode* l1 = NULL;
        ListNode* l2 = NULL;
        ListNode* temp1 = NULL;
        ListNode* temp2 = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;

        while (curr != NULL) {

            curr->next = NULL;
            //now we have current node//

            if (curr->val < x) {

                if (l1 == NULL) {

                    l1 = curr;
                    temp1 = l1;

                } else {

                    //l1 is already done//
                    temp1->next = curr;
                    temp1 = temp1->next;

                }

            } else if (curr->val >= x) {

                if (l2 == NULL) {
                    l2 = curr;
                    temp2 = l2;

                } else {
                    temp2->next = curr;
                    temp2 = temp2->next;
                }

            }

            curr = next;
            if (curr != NULL) {
                next = curr->next;
            }

        }

        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        else temp1->next =l2;

        return l1;

    }
};