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
    ListNode* rotateRight(ListNode* head, int k) {
        
        //rotating k places means last k nodes will be inserted to the head....//
        //total-kth node mark as previous and prev->next = targetnode//

        int len = 0;


        if (head == NULL) return NULL;

        ListNode* temp = head;

        while (temp) {
            len++;
            temp=temp->next;
        }

        ListNode* tail = head;

        while(tail->next){
            tail=tail->next;
        }

        //normalizing the k//

        k = k%len;

        if (k==len || k==0) return head;

        int prev_cnt = len-k;

        temp = head;
        int cnt = 0;
        while (cnt != prev_cnt) {
            cnt++;
            if (cnt == prev_cnt) break;
            temp=temp->next;

        }

        ListNode* newhead = temp->next;

        if (temp) {
        
            temp->next = NULL;
            tail->next = head;
        }

        return newhead;

    }
};