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
    void deleteNode(ListNode* node) {
        
        ListNode* nextnode = node->next;

        node->val = nextnode->val;
        nextnode = nextnode->next;
        ListNode* temp = node;
        node->next = NULL;
        while (nextnode!=NULL) {

            ListNode* other = new ListNode(nextnode->val);
            temp->next = other;
            temp = other;
            nextnode=nextnode->next;

        }

    }
};