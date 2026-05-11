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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* temp = head;
        ListNode* nextemp = temp->next;

        while (nextemp != NULL) {

            int val1 = temp->val;
            int val2 = nextemp->val;

            ListNode* newnode = new ListNode(gcd(val1,val2));

            temp->next= newnode;
            newnode->next = nextemp;
            temp = nextemp;
            nextemp = nextemp->next;



        }

        return head;

    }
};