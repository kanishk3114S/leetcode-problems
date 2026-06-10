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
    ListNode* removeNthFromEnd(ListNode* head, int k) {

        
        ListNode* temp = head;
        int len = 0;
        while (temp != NULL){
            len++;
            temp = temp->next;
        }

        if (k==len) return head->next;

        int cnt = 0;
        temp = head;
        ListNode* prev = NULL;
        while (cnt < len-k) {

            cnt++;
            prev = temp;
            temp=temp->next;

        }

        //now the task is to delete that node//

        if (prev!=NULL) {
            prev->next = temp->next;
        }

        return head;

    }
};