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

    ListNode* reverse(ListNode* curr) {

        ListNode* prev = NULL;
        ListNode* next = NULL;

        while (curr != NULL) {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }
        return prev;
    }

    int pairSum(ListNode* head) {
        
        ListNode* otherhead = new ListNode(head->val);
        ListNode* temp = head->next;
        ListNode* connect = otherhead;

        int cnt = 1;
        while (temp != NULL) {

            ListNode* newnode = new ListNode(temp->val);
            connect->next = newnode;
            connect = newnode;
            temp = temp->next;
            cnt++;
        }

        ListNode* HEAD = reverse(head);
        int i=0;
        temp = HEAD;
        connect = otherhead;
        int maxi = 0;
        while (i < cnt/2) {

            int sum = temp->val + connect->val;
            temp = temp->next;
            connect = connect->next;
            maxi = max(maxi,sum);
            i++;
        }

        return maxi;

    }
};