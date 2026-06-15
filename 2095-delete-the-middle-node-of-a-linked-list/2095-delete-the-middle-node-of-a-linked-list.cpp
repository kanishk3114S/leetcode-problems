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
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        if (fast->next==NULL) return nullptr;

        while (fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;

        }

        //middle node -> slow//

        if (slow->next == nullptr) {
            head->next = nullptr;
            return head;
        }

        slow->val = slow->next->val;
        slow->next = slow->next->next;

        return head;

    }
};